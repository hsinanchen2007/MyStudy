归纳了各路大神的 做下笔记以后复习看


基本思路
思路的话主要就是分治，相信大家都很容易理解。
先遍历一遍统计字符串S中每个字母出现的次数,然后再遍历一遍找到出现次数小于k的一个字母对应的位置（假设S[mid]对应的字母出现次数小于k）。那么包含S[mid]的子串显然不可能符合题目要求。

所以原问题求S[start,end]字符串对应的答案就等价于求S[start,mid-1]和S[mid+1,end]对应的2个答案的最大值。也即longestSubstring(S[start,end])=max(longestSubstring(S[start,mid-1]) , longestSubstring(S[mid+1,end]))

(如果mid不存在，则说明原字符串S完全符合要求，所以答案即为S.size())

最初跑248ms的3个原因
我一开始就是完全按照那个基本思路直接递归求解，但是这样的话会非常慢。可能原因如下：
(以下列举的字符串中，‘数字’ 对应数量小于k的字符)

......1234...... 若字符串如左边所示，我们不做处理直接递归求解时，找到的第一个数量小于k的字符为1，以此为基准点分割出来的左右两个子串分别为
...... 和 234......，在右子串中，前3个字符均为数量小于k的字符，那么在右子串继续递归计算的时候，又不得不重复计算多三次每个字符出现的次数。
所以在第一次递归时，如果能直接把1234这个整体作为一个分隔点(而不是只把1作为分隔点)，将原字符串分隔成为 ...... 和 ...... 再递归，则能节省时间，尤其是这个整体的长度越长时，节省的时间越多。

......1......2......3......4...... 若字符串如左边所示，如果我们不做任何处理直接递归求解时，找到的第一个数量小于k的字符为1，以此为分隔点分隔出来的左右两个子串分别为 ...... 和 ......2......3......4......
这样的话右子串在继续递归计算时，则不得不重复计算多几次每个字符出现的次数，然后找到下一个字符 2作为分隔点继续递归，而这些实际在第一次递归时，已经求出来了。
所以在第一次递归时，如果能以1 2 3 4作为分隔点分割出5个子串，再分5次去递归，则能节约不少时间。

......1...... 若字符串如左边所示，假设以1作为分隔点，左子串递归求解得到的答案是left_ans，如果此时右子串的长度right_length<=ans，那么显然这个时候右子串得到的答案right_ans显然<=right_length，那么这时候递归右子串没有意义。
所以如果能提前判断是否有必要递归计算这个子串，不必要时不递归计算该子串则能节省一些时间



解题思路：递归拆分子串，分治。先统计出每个字符出现的频次，维护一对双指针，从首尾开始统计，从首尾往中间排除，如果出现次数小于k则不可能出现在最终子串中，排除并挪动指针，然后得到临时子串，依次从头遍历，一旦发现出现频次小于k的字符，以该字符为分割线，分别递归求其最大值返回

不优化
```
class Solution {
    
  public int longestSubstring(String s, int k) {

        int len=s.length();

        if(len<k)return 0;


        return dtgh(s.toCharArray(),k,0,len);
    }


    public int dtgh(char[] chars, int k, int p1, int len){
        //动态规划后若长度小于k就不是
        if (len - p1 < k) return 0;
        //统计字符出现的次数
        int[] times=new int[26];
        for(int i=p1;i<len;i++){
            times[chars[i]-'a']++;

        }


        //如果次数小于k，那就分割动态规划
        for(int i=p1;i<len;i++){
            if(times[chars[i]-'a']<k){
                //System.out.println(times[chars[i]-'a']);
                return Math.max(dtgh(chars,k,p1,i),dtgh(chars,k,i+1,len));
            }
        }

      return len-p1;
    }
    
}
```



优化后
```
class Solution {
    
  public int longestSubstring(String s, int k) {

        int len=s.length();

        if(len<k)return 0;
        //加上下面两行就能击败100.00%的用户
        //if(len == 0 || len<k)return 0;
        //if (k < 2) return len;


        return dtgh(s.toCharArray(),k,0,len);
    }


    public int dtgh(char[] chars, int k, int p1, int len){
        //动态规划后若长度小于k就不是
        if (len - p1 < k) return 0;
        //统计字符出现的次数
        int[] times=new int[26];
        for(int i=p1;i<len;i++){
            times[chars[i]-'a']++;

        }


        //设置两个指针优化算法，不设置也行
        //若头指针小于k就右移
        //写len-p1>=k是因为要p1++若len-p1>0才行
        while(len-p1>=k &&times[chars[p1]-'a']<k){
            p1++;
        }
        //若尾指针小于k就左移
        while(len-p1>=k &&times[chars[len-1]-'a']<k){
            len--;
        }

        if(len-p1<k)return 0;
        //如果次数小于k，那就分割动态规划
        for(int i=p1;i<len;i++){
            if(times[chars[i]-'a']<k){
                //System.out.println(times[chars[i]-'a']);
                return Math.max(dtgh(chars,k,p1,i),dtgh(chars,k,i+1,len));
            }
        }

      return len-p1;
    }
}
```
