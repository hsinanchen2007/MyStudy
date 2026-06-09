### 变量设定
单词长度： len
所有单词长度总和：finallen
字符串长度：s.length()

### 怎样的滑动窗口？
滑动窗口左边： left，滑动窗口左边可以不动，可以向前动1个或者多个len
滑动窗口右边：i，滑动窗口右边每次都忘右动1个len，判定一个单词

### 怎样检测
每一轮的检测开始的位置：j，j<len，也就是从0开始检测到s.length()，然后再从1开始检测到s.length()，这样可以确保不漏掉任何一种情况
已判定长度的计算：i-left
是否监测成功： i-left == finallen

### 情况分析
words = [“bar","foo","foo","the"]  s="barthebarfoofoosetfoo"
总共只有三种情况，我们一一分析
1) 我们读到了一个正确的单词，没有重复
声明：当前读的单词是i往后len个字母的单词，对下面这种情况就是读入了“bar"
left不移动，此时我们已判定长度=3；
（注意i是种在往后移动，下次循环它就到了i=3位置）
![IMG_B8D898A763A6-1.jpeg](https://pic.leetcode-cn.com/d8e5c2c5e642acf9107e16423268e2961c270d60e7446d307181ccaacd2799c9-IMG_B8D898A763A6-1.jpeg)

2）我们读到了一个正确的单词，却重复了
left移动到，刚好能保证单词没有重复的位置，left=3，已判定长度=6（“thebar"）
![截屏2020-03-07上午10.56.53.png](https://pic.leetcode-cn.com/68e41ec11a05b1daf9184b18aa157fac95bd81ebe29601dcdc48f109a9953e0a-%E6%88%AA%E5%B1%8F2020-03-07%E4%B8%8A%E5%8D%8810.56.53.png)

3）我们读到了一个错误的单词
单词"set"错了，之前读到的所有东西全部不考虑，left=i+3=18, 已判定长度=0
![截屏2020-03-07上午10.58.42.png](https://pic.leetcode-cn.com/3c8b06c3e2a6ec725e84d64f4edf26ce5b78ba2bf33fd13c08f41af31ff95cce-%E6%88%AA%E5%B1%8F2020-03-07%E4%B8%8A%E5%8D%8810.58.42.png)

除此之外，**在每次读单词做以上三种情况分析前**，还要显式判断一下窗口是不是已经满了，即已判定长度=finallen,比如下面：如果满了，left先往后移动len个位置，再去做单词判定；
这样可以保证窗口位置始终是最新的
![截屏2020-03-07上午11.06.34.png](https://pic.leetcode-cn.com/105cb622ad6830b89471122ada37997cbc232c950551e68dd86374094f536db3-%E6%88%AA%E5%B1%8F2020-03-07%E4%B8%8A%E5%8D%8811.06.34.png)


### 具体实现
HashMap mymap 记录 words 中每个单词出现次数
HashMap mypos 记录每个单词的每一个出现的位置 如：<"bar",{0,6}> 也就是为每一个单词维护一个出现的位置的linkedlist，注意这个位置链表可能有已经过期的位置，比如left=3时，0已经过期在窗口之外； 我们要及时剔除

### 代码

```java
class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        if(s.equals("") || words.length==0) return new LinkedList<Integer>();
        HashMap<String,Integer> mymap = new HashMap<>();
        List<Integer> res =  new LinkedList<>();

        // 首先做words统计
        for(int i=0; i<words.length; i++){
            mymap.put(words[i],mymap.getOrDefault(words[i],0)+1);
        }

        int len = words[0].length();
        int finallength = len * words.length;
        int i;
        boolean flag = false;
        for(int j=0; j<len; j++){
        int left = j;
        flag = false;
        // 每一轮维护一个位置map
        HashMap<String,LinkedList<Integer>> mypos = new HashMap<>();
        for(i=j; i<s.length(); i += len ){
            //  首先判断窗口是不是已经满了，满了及时更新left
            if(i-left==finallength){
                res.add(left);
                left+=len;
            }

            //  读单词
            String sub = "";
            //  如果再读就越界了，这一轮就完了
            if(i+len>s.length()) {flag = true; break;}
            sub = s.substring(i,i+len);
          
            //  单词是错的
            if(!mymap.containsKey(sub)){
                left = i+len;
               
            }

            //  单词是对的
            else{
                int allnum = mymap.get(sub);
                if(mypos.containsKey(sub)){
                    // 获得这个单词的位置列表
                    LinkedList<Integer> poslist = mypos.get(sub);

                    //  把已经过期的位置剔除
                    while(poslist.size()!=0&&poslist.peekFirst()<left){
                        poslist.pollFirst();
                    }
                    //  再来判断是不是单词个数过多了
                    if(poslist.size()+1>allnum){
                        left = Math.max(left,poslist.peekFirst()+len);
                    }
                }
                //  别忘了把当前单词的新位置添加进去
                LinkedList<Integer> temp = mypos.getOrDefault(sub,new LinkedList<Integer>());
                temp.add(i);
                mypos.put(sub,temp);
            }
        }
       
        //  对于窗口滑到s的末尾并且读出来是一个匹配的情况，需要特殊考虑
        if(flag) i=s.length();
        if(i-left==finallength) res.add(left);
        
        }
        
        return res;
    }
}
```

### 结果
![截屏2020-03-07上午10.27.46.png](https://pic.leetcode-cn.com/6f3fe110e711fec7028fb53a3c982720f243387218665960fcb54d4f2aa5f36f-%E6%88%AA%E5%B1%8F2020-03-07%E4%B8%8A%E5%8D%8810.27.46.png)