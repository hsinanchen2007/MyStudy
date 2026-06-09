思路：
数组的总和只有三种情况：
1. mod 3 = 0
2. mod 3 = 1
3. mod 3 = 2
所以可以记录mod 3余1的最小和次小以及mod 3余2的最小和次小

- 如果求出的总和mod 3 余 1，我们可以去掉一个mod 3 余 1 的数字或者两个mod 3 余 2 的数字，二者取最小去掉。
- 如果求出的总和mod 3 余 2，我们可以去掉两个mod 3 余 1 的数字或者一个mod 3 余 2 的数字，二者取最小去掉。
- 如果求出的总和能被 3 整除，则直接返回。
```c++
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int MAX=100000, m1=MAX, mm1=MAX, m2=MAX, mm2=MAX,s=0;
        for(int &c:nums){
            s+=c;
            if(c%3==1){
                if(c<m1){
                    mm1=m1;
                    m1=c;
                }else if(c<mm1){
                    mm1=c;
                }
            }
            else if(c%3==2){
                if(c<m2){
                    mm2=m2;
                    m2=c;
                }else if(c<mm2){
                    mm2=c;
                }
            }
        }
        if (s % 3 == 1) return s - min(m1, m2 + mm2);
        if (s % 3 == 2) return s - min(m1 + mm1, m2);
        return s;

    }
};
```