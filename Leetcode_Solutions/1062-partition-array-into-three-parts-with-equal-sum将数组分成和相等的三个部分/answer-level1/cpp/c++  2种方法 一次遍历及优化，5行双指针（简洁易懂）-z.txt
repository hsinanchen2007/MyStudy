### 遍历
先计算数组的总和，然后循环遍历计算能否满足三等分的条件，
用i做记录，当i等于3时，则满足三等分，如果sum为0，i可能大于3，如[10,-10,10,-10,10,-10,10,-10]，i为4，但是也可以等分成三部分

```cpp
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum=0,temp=0,i=0;
        for(int n:A)
            sum+=n;         //计算数组总和
        for(int m:A)
        {
            temp+=m;
            if(temp==sum/3)
            {
                temp=0;
                i++;
            }
        }
        if(i>=3)    return true;    //当sum=0时，可能出现i>3的情况
        return  false;
    }
};
```

### 优化
当数组的总和不为0时，其实i=2就满足三等分条件

```cpp
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum=0,temp=0,i=0;
        if(sum%3!=0)    return false;
        for(int n:A)              
            sum+=n;       
  
        if(sum==0)  i--;                //sum为0时，还是需要满足三等分，所以令i--，如【-1，1，-1，1】，i等于2但是不满足三等分
        for(int m:A)
        {
            temp+=m;
            if(temp==sum/3)
            {
                temp=0;
                i++;
            }
            if(i==2)    return true;    
        }
        return  false;
    }
};
```

### 解题思路
双指针法debug了好多次，难受，sum为0的情况太难受了

### 代码

```cpp

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum=0,sum1=A[0],sum2=A[A.size()-1],left=1,right=A.size()-2;
        
        for(int n:A)    sum+=n;                 //计算数组总和
        while(left<right && sum1!=sum/3)        sum1+=A[left++];
        while(right>0 && sum2!=sum/3)           sum2+=A[right--];

        return sum%3==0 & left<=right;                    //如果两个三分之一之间还存在元素，则为true
    }
};


```