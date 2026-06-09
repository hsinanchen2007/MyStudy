### 解题思路
此处撰写解题思路
当循环出相同的数的时候，就是不快乐。所以需要多写一个数组存储是否有相同元素。
### 代码

```cpp
class Solution {
public:
    bool isHappy(int n){
        int num=n;
        int L;
        vector<int> a;
        while(num!=1){
            a.push_back(num);
            num=qiu(num);
            L=a.size();
            for(int i=0;i<L;i++){
                if(num==a[i])
                return false;
            }
        }
        return true;

    }
    int qiu(int n){
        int s;
        int sum=0;
        while(n!=0){
            s=n%10;
            sum=sum+s*s;
            n=n/10;
        }
        return sum;
    }
};
```