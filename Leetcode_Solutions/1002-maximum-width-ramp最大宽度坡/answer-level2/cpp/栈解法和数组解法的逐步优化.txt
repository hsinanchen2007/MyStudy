## 问题描述
给定一个整数数组 A，坡是元组 (i, j)，其中  i < j 且 A[i] <= A[j]。这样的坡的宽度为 j - i。

找出 A 中的坡的最大宽度，如果不存在，返回 0 。

![](https://pic.leetcode-cn.com/46d2c6d8042b9756a063b1c286c57c1a2c508c78c7e9012ab868b7cd8312731e.png)

[最大宽度坡](https://leetcode-cn.com/problems/maximum-width-ramp/ "最大宽度坡")


## 解决方法
### 暴力

- 首层循环，找到当前元素的索引`i`

- 第二层循环，从头开始，记第二层的索引为`j`，一旦找到`A[i]>=A[j]`，就退出第二层循环，更新最大值

```cpp
class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        int size=A.size();
        int res=0;
        for(int i=0;i<size;i++){
            for(int j=0;j<i;j++) {
                if (A[i] >= A[j]) {
                    res=max(res,i-j);
                    break;
                }
            }
        }
        return res;
    }
};
```

### 暴力优化

维护一个单调递减的数组`s`，二次循环不再去原数组中查找，而是在`s`中查找，当前减少遍历的次数

```cpp
class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        vector<int>s;
        int size=A.size(),res=0,count=0;
        s.push_back(0);
        for(int i=1;i<size;i++){
            if(A[i]<A[s[count]]){
                count++;
                s.push_back(i);
            }else{
                for(int j=0;j<=count;j++){
                    if(A[s[j]]<=A[i]){
                        res=max(res,i-s[j]);
                        break;
                    }
                }
            }
        }
        return res;
    }
};
```

### 暴力再优化
在版本二的基础上改为二分查找

```cpp
class Solution {
public:
    int helper(vector<int>& A, vector<int>& s,int num,int size){
        int left = 0,right=size;
        while (left < right) {
            int mid = (left + right)>>1;
            if (A[s[mid]] > num) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return s[left];
    }
    int maxWidthRamp(vector<int>& A) {
        vector<int>s;
        int size=A.size(),res=0,count=0;
        s.push_back(0);
        for(int i=1;i<size;i++){
            if(A[i]<A[s[count]]){
                s.push_back(i);
                count++;
            }else{
                int index=helper(A,s,A[i],count);
                res=max(res,i-index);
            }
        }
        return res;
    }
};
```


### 栈

维护一个单调栈(之前做过一个类似的题，所以这个就有经验了)

- 第一次从左往右遍历将数组中单调递减的元素索引入栈

- 第二次从右往左遍历，一旦当前元素`A[i]`大于`A[栈顶元素]`，抛出栈顶元素，更新`res`

```cpp
class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        vector<int>s;
        int size=A.size(),res=0,count=0;
        s.push_back(0);
        for(int i=1;i<size;i++){
            if(A[i]<A[s[count]]){
                count++;
                s.push_back(i);
            }else{
                for(int j=0;j<=count;j++){
                    if(A[s[j]]<=A[i]){
                        res=max(res,i-s[j]);
                        break;
                    }
                }
            }
        }
        return res;
    }
};
```


个人小站：[liyiping](https://liyiping.cn)