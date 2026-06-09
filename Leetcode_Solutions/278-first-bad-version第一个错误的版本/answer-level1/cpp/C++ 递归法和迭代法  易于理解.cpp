## 核心思想
本算法采用的是二分查找的思想，可以通过递归或者迭代来实现
第一个错误版本的左边都是false，其自身和右边都是true
注意避免溢出的写法，很不错

#### 递归法
引入了进行递归的辅助函数
```
bool isBadVersion(int version);

class Solution {
public:
    int helper(int lower,int upper){
        if(lower>=upper){
            return lower;
        }
        int mid=lower+(upper-lower)/2;
        if(isBadVersion(mid)){
            return helper(lower,mid);
        }
        else return helper(mid+1,upper);
    }
    
    int firstBadVersion(int n) {
        if(!n) return n;
        return helper(1,n);
    }
};
```

#### 迭代法
直接迭代，更直观
```
int firstBadVersion(int n) {
        int left=1;
        int right=n;
        while(left<right)//直到left==right,找到第一个地方
        {
            int mid=left+(right-left)/2;//避免溢出的精髓之处
            if(isBadVersion(mid)==false)
            {
                left=mid+1;
            }
            else{
                right=mid;
            }
        }
        return left;
    }
```

