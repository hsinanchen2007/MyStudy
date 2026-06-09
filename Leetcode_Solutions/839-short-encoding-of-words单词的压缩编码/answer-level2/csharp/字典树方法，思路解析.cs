根据题意, 如果想要知道两个单词是否可以被压缩，那么就相当于比较其中一个单词是不是另一个单词的结尾。
例如`time`和`me`，那么`me`就是`time`的结尾，那么如果将字符串倒序遍历并比较（就好比把单词倒过来），那么就像相当于找头相同的。

这样我们定义树结构，就可以从单词的最后一个字母出发，作为根节点的叶子节点
例如 `time` 就会被映射为 
```
root
|--e
   |--m
      |--i
         |--t
```

遍历`me`的时候，就会先去root下查找有没有e，有，则继续在e节点下查找有没有m，有，单词遍历结束。

那么我们来分析一下，在遍历映射单词的时会出现那些问题。

- 1、现有字典树内存在。
   也就是在上面写的，time这个单词已经按倒序存到了字典库里，在遍历me的时候，
   每一个字母都会在字典树上找到相应路径的。这种单词我们认为该单词可以被压缩进某一个单词内，进而**不会**影响索引字符串的长度。

- 2、延长
   上面的例子是，time这个单词已经在检索树内，来查找me。但是如果是me在字典树内，而现在要查找的是time呢？
   那么会出现一个问题，当我在m节点下查找i时候，发现找不到了，并且m节点下**没有任何其他子节点**。我们这时候可以认为当前单词是对，某一个压缩单词的延长和扩展。那么仅需**将当前单词未遍历到的长度加到索引字符串的长度上**即可。

- 3、分支
   还是在time已经存在于字典树内，现在要查找的是same。
   同样当我在m节点下查找a时无法找到节点，但是m节点下**已经有其他的子节点**（i节点）.
   按照题意出现分支，我们需要将当前完整的单词，加到索引字符串内，并增加一个#。
   只需要将**当前单词的完整长度+1加到索引字符串长度上**即可。

根据以上逻辑我们可以得出
```C# []
public class Solution {
    public int MinimumLengthEncoding(string[] words) {
        
        int MinLength = 0;
        
        LetterTree Root = new LetterTree();
        Root.letters = new LetterTree[26];
        
        foreach(var word in words)
        {
            var current = Root;
            
            for (int i = word.Length - 1; i >= 0; i--)
            {
                int index = word[i] - 'a';
                if(current.letters == null)
                {
                    //路径存在，但需要延长
                    //加上当前单词剩余长度
                    MinLength++;
                    current.letters = new LetterTree [26];
                    current.letters[index] = new LetterTree();
                    current = current.letters[index];
                    
                }
                else 
                {
                    if(current.letters[index] == null)
                    {
                        //当前路径存在，但需要新的分支
                        //那么需要增加一个#号，以及当前完整单词
                        MinLength += word.Length - i + 1;
                        
                        current.letters[index] = new LetterTree();
                        current = current.letters[index];
                    }
                    else
                    {
                        //当前路径存在，且存在分支，接续向下查找
                        current = current.letters[index];
                    }
                }
            }
        }
        
        return MinLength;
    }
    
    //该结构可以用字典类替代，但是考虑到，字典类和数组都是在堆上分配资源，
    //且字典类型的处理过程要更复杂，会影响到处理时间和内存，所以定义一个这样的简单类型来实现。
    private class LetterTree {
        public LetterTree [] letters;
    }
}
```



