#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster but larger
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster
static auto x = [](){ios_base::sync_with_stdio(false); cin.tie(NULL); return NULL;}();

class Solution {
public:
    int reverse(int x) {
      // [-2^31, 2^31 - 1]

      long result = 0;
      while (x != 0) {
        result = result * 10 + x % 10;
        if (result > INT_MAX || result < INT_MIN)
            return 0;
        x /= 10;
      }
      return result;
    }

    int reverseOnlyInt(int x) {
      // [-2^31, 2^31 - 1]
      const static int minNumber = -2147483648;
      const static int maxNumber = 2147483647;
      const static int minNumber10 = minNumber / 10;
      const static int maxNumber10 = maxNumber / 10;

      int result = 0;
      while (x != 0) {
        int digit = x % 10;
        x /= 10;
        if ((result > 214748364) || ((result == 214748364) && digit > 7))
            return 0;
        if ((result < -214748364) || ((result == -214748364) && digit < -8))
            return 0;
        result *= 10;
        result += digit;
      }
      return result;
    }
};

void test1() {
  Solution S;
  cout << "321? " << S.reverse(123) << endl;
}

void test2() {
  Solution S;
  cout << "-321? " << S.reverse(-123) << endl;
}

void test3() {
  Solution S;
  cout << "21? " << S.reverse(120) << endl;

  // 1534236469
    cout << "??? " << S.reverse(1534236469) << endl;

}

int main() {
  test1();
  test2();
  test3();
  cout << "Done!" << endl;
  
  return 0;
}

