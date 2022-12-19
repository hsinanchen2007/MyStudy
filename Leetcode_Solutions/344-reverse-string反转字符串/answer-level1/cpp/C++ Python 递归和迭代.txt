
对于一个数组[a, b, c, d, e]，我们先交换首尾元素，然后中间元素看成是另一个子问题，然后递归求解

### 递归版

```
class Solution {
public:
    void reverseString(vector<char>& s) {
        help(s, 0, s.size()-1);
    }
    
    void help(vector<char>& s, int start, int end) {
        //终止条件
        if(start >= end)
            return;
        //处理本次
        swap(s, start, end);
        //规模递减，递归
        help(s, start+1, end-1);
    }

    void swap(vector<char>& s, int i, int j)
    {
        char c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
};
```

```python
class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        def help(s:List[str], i:int, j:int) ->None :
            assert(i>=0 and j < len(s))
            if i >= j:
                return
            s[i], s[j] = s[j], s[i]
            help(s, i+1, j-1)

        help(s, 0, len(s)-1)
```

### 迭代版

```cpp
class Solution {
public:

    void reverseString(vector<char>& s) {
        int i = 0;
        int j = s.size()-1;
        while(i < j)
        {
            char tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
            i++;
            j--;
        }
    }
    void swap(vector<char>& s, int i, int j)
    {
        if(i<0 || j >= s.size()) return;
        cout << s[i] << " "<<s[j] << endl;
        char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
};
```

```python
class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        i = 0
        j = len(s)-1
        while i < j:
            s[i], s[j] = s[j], s[i]
            i = i+1
            j = j-1
```

进一步提高性能，上面提交后超过77%左右，把swap里的内容直接写，避免函数调用，可以提高到97%


