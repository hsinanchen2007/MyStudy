### 解题思路
1、首先我们考虑无重复字符的情况，也就是形如abcbacacb这样的形式
   我们建立一个List<Character> list来保存无重复的子串
   lastIndex = s.length-1;
   int startIndex = 0;
   int maxLength = 0; 
   那么假定我们已经保存了abc这样的列表，当加入了一个新字符包含在这个列表的时候，例如b
       我们应该先计算当前无重复列表的长度，与maxLength进行比较。
           然后获取原有列表里面从b所在位置的开始的子列表,作为当前无重复的子列表
   现在可以把b加入到list中了         

   while(startIndex<=lastIndex){
        Character currentChar = s.charAt(startIndex);
        if(list.contains(currentChar)){
            maxLength = Math.max(list.size(),maxLength);
            int firstIndex = list.indexOf(currentChar);
            if(firstIndex=list.size()-1){
                 //最后一个字符跟当前字符相同
                 list.clear();       
            }else{
                list = list.subList(firstIndex+1,list.size());
            }            
        }
        list.add(currentChar);
        startIndex++;
    }
    //最后我们要判断下list是否为空
    if(!list.isEmpty()){
        maxLength = Math.max(list.size(),maxLegnth);
    } 

2、接下来我们考虑在有重复字符的情况
以eabcbeea为例
我们在碰到第二个e的时候，此时list = [abcb]
或者以abcdeea为例
我们在碰到第二个e的时候，此时list = []
这时我们知道list与e结合是一个无重复字符列表，并且下一个无重复字符串肯定是[e]
所以我们在list截取之后,做一个下一个字符判断
int nextIndex = startIndex+1;
if(nextIndex<=lastIndex&&s.chartAt(nextIndex)==currentChar){
    list.add(currentChar);
    maxLength = Math.max(list.size(),maxLength);
    list.clear();
    //然后提前移动startIndex
    while(nextIndex<=lastIndex&&s.chartAt(nextIndex)==currentChar){
        startIndex = nextIndex;
        nextIndex+=1;
    }    
}
把这一段逻辑加到if contains的判断里面

    
### 代码

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        if (s == null) {
            return 0;
        }
        if (s.length() == 1) {
            return 1;
        }
        List<Character> list = new ArrayList<>();
        int maxLength = 0;
        int lastIndex = s.length() - 1;
        int startIndex = 0;
        while (startIndex <= lastIndex) {
            char currentChar = s.charAt(startIndex);
            if (list.contains(currentChar)) {
                maxLength = Math.max(maxLength, list.size());
                //找出currentChar在list其中的位置t
                //获得从位置t到list结束的新索引
                int firstIndex = list.indexOf(currentChar);
                if (firstIndex == list.size() - 1) {
                    list.clear();
                } else {
                    list = list.subList(firstIndex + 1, list.size());
                }
            }
            int nextIndex = startIndex + 1;
            if(nextIndex<=lastIndex && s.charAt(nextIndex)==currentChar){
                list.add(currentChar);
                maxLength = Math.max(maxLength, list.size());
                while (nextIndex <= lastIndex && s.charAt(nextIndex) == currentChar) {
                    startIndex = nextIndex;
                    nextIndex += 1;
                }
                list.clear();
            }
            list.add(currentChar);
            startIndex++;
        }
        if (!list.isEmpty()) {
            maxLength = Math.max(maxLength, list.size());
        }
        return maxLength;
    }
}
```