### 解题思路
对于无重复值的情况
把第一个字符与后面每一个字符交换，获得一个排列；然后固定第一个字符，递归求后面的字符串组合。

    这个都很简单，我想大家也都理解

假如有重复值呢？
例如abb，第一个字符与后面两个字符交换得bab，bba。然后abb中第二个字符和第三个字符相同，就不用交换了。但是对 bab，第二个字符和第三个字符不同，则需要交换，得到 bba。由于这里的bba和开始第一个字符与第三个字符交换的结果相同了，因此这个方法不行。

解决办法：对 abb，第一个字符a与第二个字符b交换得到 bab，然后考虑第一个字符与第三个字符交换，此时由于第三个字符等于第二个字符，所以第一个字符就不再用与第三个字符交换了。再考虑bab，它的第二个字符与第三个字符交换可以解决bba。此时全排列生成完毕！

修改的策略：第一个字符起，每个字符分别与它后面的字符交换，如果后面的字符中有重复的字符，那么第一个字符仅与其中的一个进行交换，跳过其他重复的。

如何判断重复？在每次递归中，都设置一个hash，记录交换过的字符，下次再遇到的时候，就跳过去。


### 代码

```java
class Solution {
    char[] chars;
    LinkedList<String> res;
    public String[] permutation(String s) {
        //回溯
        this.chars = s.toCharArray();
        this.res = new LinkedList<>();
        traceBack(0,s.length());
        return res.toArray(new String[res.size()]);
    }
    void traceBack(int start,int end){
        if(start==end){
            res.add(new String(chars));
            return;
        }
        boolean[] used = new boolean[128];//这里用的是字符的ascii码值 0-127
        for(int i = start;i < end;i++){
            if(used[chars[i]]==true) continue;//重复的就不在交换了
            used[chars[i]] = true;
            swap(start,i);
            traceBack(start + 1,end);
            swap(start,i);
        }
    }
    void swap(int start,int i){
        char temp = chars[start];
        chars[start] = chars[i];
        chars[i] = temp;
    }

}
```