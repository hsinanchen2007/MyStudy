## 问题描述
给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

![](https://pic.leetcode-cn.com/aac90f9b3ceae0e6fde9399c97eb2a9500b2ded418adfbe31c5e75ba56f2ad1b.png)

[字符串相乘](https://leetcode-cn.com/problems/multiply-strings/ "字符串相乘")

## 解决方法


### 普通做法
```bash
     7 8 9 6 5 2
×       3 2 1 1
-----------------
     7 8 9 6 5 2   <---- 第1趟 
   7 8 9 6 5 2     <---- 第2趟 
  ..........       <---- 第n趟 
-----------------
 ? ? ? ? ? ? ? ?   <---- 最后的值用另一个数组表示 
```
```cpp
// class Solution {
// public:
//     //字符串相加
//     string addStrings(string num1, string num2) {
//         int len1=num1.size()-1,len2=num2.size()-1;
//         int flag=0;//进位标志
//         string res;
//         while(len1>=0 || len2>=0){
//             int n1=len1>=0?num1[len1]-'0':0;
//             int n2=len2>=0?num2[len2]-'0':0;
//             int temp=n1+n2+flag;
//             flag=temp/10;
//             res.insert(res.begin(),temp%10+'0');
//             len1--,len2--;
//         }
//         return flag?'1'+res:res;
//     }
//     //字符串相乘
//     string multiply(string num1, string num2) {
//         if(num2=="0" || num1=="0")return "0";
//         int size=num2.size()-1;
//         string res;
//         for(int i=0;i<=size;i++){
            
//             int flag=0;
//             int n2=num2[size-i]-'0';
//             string temp;
//             int len=num1.size()-1;
//             while(len>=0){
//                 int n1=num1[len]-'0';
//                 int tmp=n1*n2+flag;
//                 flag=tmp/10;
//                 temp.insert(temp.begin(),tmp%10+'0');
//                 len--;
//             }
//             if(flag>0)temp.insert(temp.begin(),flag+'0');
//             for(int j=0;j<i;j++)temp+='0';
//             res=addStrings(res,temp);
//         }
//         return res;
//     }
// };
```
### 分治

算法课郭楠老师讲过，先记一下，回头补上

### 竖式相乘

两个数字相乘，结果的位数不会大于两个数字位数之和。

该算法是通过两数相乘时，乘数某位与被乘数某位相乘，与产生结果的位置的规律来完成。具体规律如下：
```bash
    乘数 `num1` 位数为 `M`，被乘数 `num2` 位数为 `N`， `num1 x num2` 结果 `res` 最大总位数为 `M+N`
	
    `num1[i] x num2[j]` 的结果为 `temp`(位数为两位，"0x","xy"的形式)，其第一位位于 `res[i+j]`，第二位位于 `res[i+j+1]`。
```
如下图的变换过程
![](https://pic.leetcode-cn.com/02b7323a5d60a528fa2679c64560547fb2266107c353eb1c1b395effe1944196.png)

![](https://pic.leetcode-cn.com/44df1becd41cdef87ae54bb55a2ab4019cf32a25348f053338e2821bd314fd92.png)

```cpp
class Solution {
public:
    //字符串相乘
    string multiply(string num1, string num2) {
        int len1=num1.size()-1,len2=num2.size()-1;
        string res(len1+len2+2,'0');

        for (int i = len1; i >= 0; i--){
            for (int j = len2; j >=0; j--){
                int temp=(res[i+j+1]-'0')+(num1[i]-'0')*(num2[j]-'0');
                res[i+j+1]=temp%10+'0';
                res[i+j]+=temp/10;
            }
        }

        for(int i=0;i<len1+len2+2;i++){
            if(res[i]!='0')
                return res.substr(i);
        }
        return "0";

    }
};
```


参考： https://leetcode-cn.com/problems/multiply-strings/solution/you-hua-ban-shu-shi-da-bai-994-by-breezean/ "优化竖式"


个人网站：[liyiping](https://liyiping.cn)