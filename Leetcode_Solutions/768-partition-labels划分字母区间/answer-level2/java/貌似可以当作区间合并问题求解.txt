我看好多人都用贪心算法，emmm，但是这道题的第一感觉类似于前面的某道 区间合并问题，具体忘了是哪一道题了。
所以提供一个区间合并的解法

思路如下：
首先定义一个简单的类，用来代表每一个字符，该类中有两个主要的成员变量，第一次出现的地方，第二次出现的地方
```java
static class cus_char{
    // 这个主要用来方便调试，知道当前的对象表示哪一个字符。
    char cur = ' ';
    // 该字符在字符串里第一次出现的地方
    int begin = -1;
    // 该字符在字符串里最后一次出现的地方
    int end = -1;

    public cus_char(char x){
        cur = x;
    }
}
```
这样，我们就得到了每个字符的出现区间，这道题也就自然而然地转化为一个区间合并问题

然后，我们需要对这些区间排序，自定义一个比较器，用于对cus_char数组排序
```java
static class mycmp implements Comparator<cus_char>{
    @Override
    public int compare(cus_char o1, cus_char o2) {
        return o1.begin - o2.begin;
    }
}
```
排序完毕之后，那些在字符串中没有出现过地字符都会被丢到前面去，因为它们地begin变量都是-1

然后就是区间合并的常规操作了
```java
    // 排序
    Arrays.sort(chars, new mycmp());
    
    // 区间合并开始

    // 定义一个临时变量，用来存储合并后的区间
    cus_char temp = new cus_char('#');
    // 初始化该临时变量，将其初始化为从0开始到0结束的区间。
    temp.begin = 0;
    temp.end = 0;
    for(int i = 0; i < 26; i++){
        if(chars[i].begin == -1){
            // 当begin=-1，属于未初始化过的区间，说明是没有出现过的字符，直接跳过它们
            continue;
        }
        // 判断 当前节点代表的区间 是否和 已有的区间 存在重叠
        if(chars[i].begin > temp.end){
            // 发现不存在重叠区域，说明前一个区间和当前节点之间没有关联，属于一个独立区间，符合题目定义的“片段”
            // 触发将该独立区间提取出去的操作
            // 首先执行提取操作，计算该独立区间的长度
            int ans_temp = temp.end - temp.begin + 1;
            ans.add(ans_temp);
            // 然后对temp节点执行重置操作
            temp.begin = chars[i].begin;
            temp.end = chars[i].end;
        }else {
            // 发现存在一部分区间重叠，尝试合并区间
            if(chars[i].end > temp.end){
                temp.end = chars[i].end;
            }
        }
    }
    // 对于最后一段，手工执行提取独立区间的操作
    int ans_temp = temp.end - temp.begin + 1;
    ans.add(ans_temp);
```

以下是全部的源代码（太长不看系列）:
```java
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

public class solution1 {
    public static void main(String[] args){
        try{
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            String input = br.readLine().trim();
            partitionLabels(input);
            for(int i:ans){
                System.out.println(i);
            }
        }catch (Exception e){
            e.printStackTrace();
        }
    }

    public  static List<Integer> partitionLabels(String S) {
        // 由于ans是一个静态变量，对于***来说没有问题，***每次都是重新运行main函数
        // 但是对于leetcode则是多次调用这个类，所以需要重置ans，否则上一个数据的答案还在里面。
        ans = new ArrayList<>();
        solution(S);
        return ans;
    }

    static List<Integer> ans = new ArrayList<>();
    public static void solution(String input){

        cus_char[] chars = new cus_char[26];
        for(int i = 0; i < 26; i++){
            chars[i] = new cus_char((char)('a' + i));
        }
        for(int i = 0; i < input.length(); i++){
            char cur_char = input.charAt(i);
            int index = cur_char - 'a';
            if(chars[index].begin == -1){
                // 说明该字符头一次出现
                chars[index].begin = i;
                chars[index].end = i;
            }else {
                chars[index].end = i;
            }
        }
        Arrays.sort(chars, new mycmp());
        // 排序完成

        cus_char temp = new cus_char('#');
        temp.begin = 0;
        temp.end = 0;
        for(int i = 0; i < 26; i++){
            if(chars[i].begin == -1){
                continue;
            }
            // 判断当前节点的区间是否和已有的区间重叠
            if(chars[i].begin > temp.end){
                // 发现是一个新的区间
                // 首先执行提取操作
                int ans_temp = temp.end - temp.begin + 1;
                ans.add(ans_temp);
                // 然后对temp节点执行重置操作
                temp.begin = chars[i].begin;
                temp.end = chars[i].end;
            }else {
                // 发现有一部分区间重叠
                if(chars[i].end > temp.end){
                    temp.end = chars[i].end;
                }
            }
        }
        // 对于最后一段，没办法触发提取操作
        int ans_temp = temp.end - temp.begin + 1;
        ans.add(ans_temp);
    }
    
    static class mycmp implements Comparator<cus_char>{
        @Override
        public int compare(cus_char o1, cus_char o2) {
            return o1.begin - o2.begin;
        }
    }

    static class cus_char{
        char cur = ' ';
        int begin = -1;
        int end = -1;
        public cus_char(char x){
            cur = x;
        }
    }
}
```