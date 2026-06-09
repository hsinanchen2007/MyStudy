```
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int i = 0;
        int j = letters.size()-1;
        int m = 0;
        while(i<j)
        {
            m = (i+j)/2;
            if(target<letters[m] || target >= letters[j])
            {
                j = m;
            }
            else
            {
                i = m+1;
            }
        }
        return letters[i];
    }
};
```
