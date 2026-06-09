### 解题思路
此处撰写解题思路
突然 发现循环还真是 好东西 一般的 问题 暴力 解法 都能成功 ，但是 还是 比较 耗费内存 n1和 时间 n2了 
### 代码

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
       int result =0;
        List list=new ArrayList();
        // 进行 遍历 查找 最大的 数据
        for(int i=0;i<s.length();i++ ){
            for(int j=i;j<s.length();j++) {
                if (list.contains(s.charAt(j))) {
                    list.clear();
                    break;
                }
                list.add(s.charAt(j));
                if (result < list.size()) {
                    result = list.size();
                }
            }
        }
        System.out.println(result);
        return result;

    }
}
```