**【历史重难点题目】**
* [历史重难点题目总结](https://mp.weixin.qq.com/mp/homepage?__biz=MzI4Njc4MzMwMw==&hid=1&sn=58bf8e995138b26984c05fd51f198196)

**【核心思想】**
* 利用康托编码的思想，从**最高位逐步确定到最低位**

**【思路】**
* 先把n个数依次装进一个list
* 假设`n=4,k=9`，那么我们对排列分组
1. `1234,1243,1324,1342,1423,1432`
2. `2134,2143,2314,2341,2413,2431`
3. `3124,3142,3214,3241,3412,3421`
4. `4123,4132,4213,4231,4312,4321`
* 我们发现每一组的最高位都是一样的，且**最高位=组数**，每一组的数目是6，即`base=(n-1)!`
* 先用`num=k/base`来确定返回的数的（组数）最高位，用`m=k%base`来确定该组的第几个数
1. 如果能整除，则最高位在list中的序号为`num-1`（注意序号从0开始，所以要减一）；在该组的第`base`个数
2. 如果不能整除，则最高位在list中的序号为`num`；在该组的第`m`个数

* 从list中删去最高位，调用同样的函数，此时传入的参数`k=m`


**【代码】**
```java
class Solution {
  	public String getPermutation(int n, int k) {
        List<Integer> list=new ArrayList<>();
        for(int i=1;i<=n;i++)
            list.add(i);
        return help(list,k,new StringBuilder()).toString();
    }

    StringBuilder help(List<Integer> list, int k,StringBuilder ans){
        int base=1;
        int len=list.size();
        if(len==1){
            ans.append(list.get(0));
            return ans;
        }
        int num,m;


        for(int i=1;i<len;i++)
            base=base*i;

        num=k/base;
        m=k%base;
        if(m==0){
            num--;
            m=base;
        }
        
        ans.append(list.get(num));
        list.remove(num);
        help(list, m,ans);
        return ans;

    }
}
```
**【备注】**
* 帮到你了的话，关注微信公众号吧，带你拿大厂offer
![logo_gif.gif](https://pic.leetcode-cn.com/b0fab84846833f30668b19d7fe129f0947751244372b8c7cb29d89ad580ecb49-logo_gif.gif)

