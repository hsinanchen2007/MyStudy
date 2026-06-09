### 解题思路
两个解法
1.双指针
s有一个指针，t有一个，循环遍历s，如果在t中没找到s的字符，那么t的指针往后移动。如果找到s中的字符，这时候s的指针和t的指针就共同一起往后移一位。如果在t中指针.next=Null，则证明不包含子序列，这个时候返回false
2.用库函数
Java里面有个函数t.indexOf(char i,int m)，指的是从t字符串的m处开始寻找char i，找到了就返回该值，没有找到就返回-1，如果是-1，那么久返回false，其余情况返回true，这个方法因为调用库函数，所以时间复杂度和空间复杂度都很低。

### 代码

```java
class Solution {
    public boolean isSubsequence(String s, String t) {
          char[] arr=s.toCharArray();
          int j=-1;
          for(int i=0;i<s.length();i++)
          {
              j=t.indexOf(arr[i],j+1);
              if(j==-1)
              {
                  return false;
              }
          }
      return true;
    }
}
```