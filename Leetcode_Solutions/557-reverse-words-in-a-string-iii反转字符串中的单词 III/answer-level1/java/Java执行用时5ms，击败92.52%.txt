### 解题思路
最先想到的是栈，不用考虑角标值的烦恼，但是执行用时16ms，有点慢了。
第二版沿用了第344题反转字符串的思路做下来的，就是每一个局部单词用一下头尾双指针进行一下反转。需要额外注意的就是结尾单词的反转了，角标需要仔细想一下。代码如下：

### 代码

```java
class Solution {
    public String reverseWords(String s) {
        char[] arr = s.toCharArray();
        int count = 0; // store the length of each word
        for(int i = 0; i < arr.length; i++) {
            if(arr[i] != ' ') {
                count += 1;
            }
            else {
                for(int j = 0; j < count / 2; j++) { // j rep step size
                    char tmp = arr[i - 1 - j];
                    arr[i - 1 - j] = arr[i - count + j];
                    arr[i - count + j] = tmp;
                }
                count = 0;
            }
            if(i == arr.length - 1) { // 到达最后一个单词的末尾
                for(int j = 0; j < count / 2; j++) {
                    char tmp = arr[i - j];
                    arr[i - j] = arr[i - count + 1 + j];
                    arr[i - count + 1 + j] = tmp;                        
                }
                count = 0;    
            }
        }
        return String.valueOf(arr);
    }
}
```