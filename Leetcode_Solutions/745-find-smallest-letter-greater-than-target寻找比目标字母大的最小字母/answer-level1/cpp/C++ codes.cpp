
```
代码块class Solution 
{
public:
    char nextGreatestLetter(vector<char>& letters, char target) 
    {   //特殊情况：
        if(target < letters[0] || target >= letters[letters.size()-1])
            return letters[0];
        else
        {   //Binary Search
            int l = 0, h = letters.size() - 1;
            while(l <= h)
            {
                int m = l + (h - l)/2;
                if(letters[m] > target)
                    h = m - 1;
                else if(letters[m] <= target)
                    l = m + 1;
            }
            return letters[l];
        }
            
    }
};
```
