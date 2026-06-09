### 解题思路
#### 1. 分析：
1. 先手工求排列：固定第一个字符，然后求剩余字符串的排列（再固定一个字符，再求剩余字符串的排列（再固定一个字符，再求剩余字符串的排列（再固定一个字符，再求剩余字符串的排列）））。。。
2. 显然是递归的思路
（执行过程也就是 树的DFS）

#### 2. 算法流程
* 变量：
	1. 全局临时 StringBuilder，用来存放字符串
	2. 全局 String数组，用来存放结果

###### 递归：
1. 功能：轮流（遍历）固定一个字符，然后求剩余字符的排列
2. 结束条件：剩余字符串长度为0

### 代码

```java []
class Solution {
    List<String> res=new ArrayList(); //结果字符串数组
    StringBuilder cur=new StringBuilder();
    public String[] permutation(String s) {
        recur(s);
        return res.toArray(new String[res.size()]);
    }
    //递归：每个字符轮流当第一个，然后对剩余字符排列。结束条件：没有剩余字符，则把当前串加入结果集中【相当于树的遍历】
    void recur(String str){
        if(str.length()==0){
            res.add(cur.toString());
            return;
        }
        Set<Character> set=new HashSet(); //剪枝去重，字符相同的就不必再递归了
        for(int i=str.length()-1;i>=0;--i){
            if(!set.add(str.charAt(i))){continue;}
            cur.append(str.charAt(i));
            String substr=str.substring(0,i)+str.substring(i+1);
            recur(substr);
            cur.deleteCharAt(cur.length()-1);
        }
    }
}
```
### 复杂度分析：
 * 时间复杂度：执行次数约等于执行树的节点数，直接计算不好算，可以从结果来看，字符串长为a的排列组合结果 ≈ a！所以时间复杂度 ≈ O(n！)
 * 空间复杂度：递归会有额外的栈开销、生成子串、用于剪枝的set，空间复杂度 ≈ O(3n！) ≈ O(n！)
 * 时空复杂度还是不太会算呀，感觉算的有点问题😱