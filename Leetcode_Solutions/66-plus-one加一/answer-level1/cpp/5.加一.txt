### 解题思路
第一次提交忘了数组全为99的情况 加黑部分是第二次补充的
vector注意下，动态大小的只需要vector<int> a以及使用a.push_back(x)就可以了

### 代码

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i=digits.size()-1,flag=0;
        #vector<int> all9;
        if((digits[i]+1)<=9) digits[i]++;
        else{
            while(digits[i]==9){//只要进入这个循环意味着digits第i位为9
             digits[i]=0;
             if(i!=0){
                i=i-1;
             }#else{//最高位也是9产生了进位 只可能是原来数组都为9的情况
                 all9.push_back(1);
                 for(int j=1;j<=digits.size();j++) all9.push_back(0);
                 flag=1;
             }
            }
            digits[i]++;//退出while循环后只要给此时的ii所在的位置加一就可以了 后面的已经全部为0了
        } 
        if(!flag)
        return digits;
       # else return all9;
    }
};
```