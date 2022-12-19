```
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int start = 0;
        int end = letters.size() - 1;
        char c = '#';
        int mid;
        while(start <= end)
        {
            mid = start + (end - start) / 2;
            if(letters[mid] > target)
            {
                c = letters[mid];
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        } 
        return c == '#' ? letters[0] : c;
    }
};
```
