#### 找到左边索引left,右边界索引 i ，i-left+1 和之前得到的max取大者
#### 使用一个hash(php万能的数组哈哈) processed来存储 元素最后一次被考察时在字符串里的索引
>比如processed['a'] =1   a最后一次出现在字符串里索引为1


#### 考察元素，分2种
##### 1.元素item首次进来
       left不变,i-left+1是正在考察符合条件区间的的元素数，记录为nowMax,max是从开始遍历的最大符合的区间元素数
       最大值为max,nowMax的最大值,记录processed[item]=i
##### 2.元素item非首次(processed里有记录了)
        这时，准备改变left,这个元素上次时索引为 processed[item],    准备把left改为process[item]+1
        但是如果现在的left已经在process[item]+1的右边了，就不需要改变了
        比如abba,当要考察第二个b时，left=0,processed[b]=1,processed[b]+1=2>left
        left=2,当要考察第二个a时，processed[a]+1=1 <现在的left ,所以无需改变


```
   function lengthOfLongestSubstring($s) {
        $left=0;
        $len=strlen($s);
        $max=0;
        $processed=[];//已经遍历过的元素的最大索引值
        for($i=0;$i<$len;$i++){
            $item=$s{$i};
            if(isset($processed[$item])){
                if($processed[$item]+1>$left){
                    $left=$processed[$item]+1;
                }

            }
            $nowMax=$i-$left+1;
            $max=max($nowMax,$max);
            $processed[$item]=$i;
        }
        return $max;
    }
```
分析例子,要考察abbacade
```
0 1 2 3 4 5 6 7                 元素索引
----------------
a b b a c a d e                 processed=[],max=0
i=0,item=a,left=0  nowMax=i-left+1=1 =>processed=['a'=>0],max=1
i=1,item=b,left=0, nowMax=i-left+1=2 =>processed=['a'=>0,'b'=>1],max=2
i=2,item=b,processed['b']=1,left<processed['b']+1,left=2 nowMax=1=>processed=['a'=>0,'b'=>2],max=2
i=3,item=a,processed['a']=0,left=2>processed['a']+1,left不变=2,nowMax=2 =>processed=[a=>3,b=>2] max=2
i=4,item=c nowMax=3                                                     =>processed=[a=>3,b=>2,c=>4] max=3
i=5,item=a processed['a']=3,processed['a']+1=4 >left,left=4,nowMax=2  =>processed[a=>5,b=>2,c=>4] max=3
i=6,item=d nowMax=3 =>processed[a=>5,b=>2,c=>4,d=>6] max=3
i=7,item=e nowMax=4  =>processed[a=>5,b=>2,c=>4,d=>6,e=>7] max=4
```
