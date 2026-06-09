### 解题思路
此处撰写解题思路
1. 后一个数如果不是质数，它一定可以被之前的质数整除
2. 如果他是一个质数，那么他的因数一定在 2 -> sqrt(n) 之间
3. 后面的因数可以借助之前的因数判断 


### 代码

```cpp
class Solution {
public:
    int countPrimes(int n) {
        vector<int> ret;
        ret.push_back(2);
        ret.push_back(3);
        ret.push_back(5);
        ret.push_back(7);
        ret.push_back(11);

        if(n == 0 || n == 1){
            return 0;
        } else if(n <= 11) {
            int i = 0;
            
            for(int j = 0 ; j < ret.size(); j++) {
                if(ret[j] < n) {
                    i++;
                } else {
                    break;
                }
            }
            return i;
        }

        bool is = true;

        for(int k = 12; k < n ; k++) {
            is = true;

            for (int i = 0; i < ret.size(); i++) {
                if( ret[i] * ret[i] > k ) {
                    break;
                }

                if(k % ret[i] == 0 ) {
                    is = false;
                    break;
                }
            }

            if(is) {
                //cout << k <<endl;;
                ret.push_back(k);
            }
        }

        return ret.size();
    }
};
```