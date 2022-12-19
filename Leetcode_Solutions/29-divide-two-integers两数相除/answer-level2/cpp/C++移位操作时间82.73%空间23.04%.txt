leetcode给的编译器对负数的左移位会报错，所以用a+a来代替负数左移。
本题最麻烦的地方在于要随时判断左移会不会溢出。。
```
class Solution {
public:
    int divide(int dividend, int divisor) {
	    bool negative_sign = (dividend > 0) ^ (divisor > 0);    //两个数是否异号
	    if(dividend > 0)
		    dividend = - dividend;
	    if(divisor > 0)
		    divisor = - divisor;
	    int ans = 0;
	    while(dividend <= divisor){
		    int tmp_result = -1;
		    int tmp_divisor = divisor;
		    if(!(tmp_divisor < (INT_MIN >> 1))) {    //如果tmp_divisor已经小于INT_MIN/2说明不需进入循环
			    while (dividend <= (tmp_divisor + tmp_divisor)) {  //目标是除以当前能被除以的最小(负数所以是最小)
				    if (tmp_divisor <= (INT_MIN >> 1))   //如果tmp_divisor再移位就要溢出了，则不移位了
					    break;
				    tmp_divisor = (tmp_divisor + tmp_divisor);   // 否则移位
				    tmp_result = (tmp_result + tmp_result);
				    if (tmp_divisor < (INT_MIN >> 1))   // 如果移位后导致小于INT_MIN/2说明商不需要再*2了
					    break;
			    }
		    }
		    ans += tmp_result;
		    dividend -= tmp_divisor;
	    }
	    if(!negative_sign){     //如果同号
		    if(ans == INT_MIN)  //如果等于整数下界则溢出
			    return INT_MAX;
		    ans = -ans;
	    }
	    return ans;
    }
};
```
