### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {

    Map<Integer,Integer> tmp = new HashMap<>();//用来保存已经搜索过的结果
    public int numDecodings(String s) {
        return dfs(0,s);
    }

    int dfs(int index,String s){
        //超出长度结束递归为什么是1？例输入单字符'6'递归结束时就是一种结果，可以输入一些简单字符串来判断结束递归的条件
        if(index>=s.length()){
            return 1;
        }
        //字符串以0开头，没有任何结果
        if(s.charAt(index)=='0'){
            return 0;
        }

        //以226123这个字符串为例，先进行(2)(2)6123第一个递归的时候已经把6123这个子串结果计算出来了，那么进行第二个递归的时候(22)6123直接从tmp拿结果
        int m = tmp.getOrDefault(index, -1);
        if(m!=-1){
            return tmp.get(index);
        }

        int a = 0;
        int b = 0;
        
        a = dfs(index+1,s);//(2)26;
        //270111，最大值不能大于26，例如27大于26不符合条件
        if(index+1<s.length() && Integer.valueOf(s.substring(index,index+2))<=26){
            b = dfs(index+2,s);//(22)6
        }
        tmp.put(index,a+b);
        return a+b;
    }
}
```