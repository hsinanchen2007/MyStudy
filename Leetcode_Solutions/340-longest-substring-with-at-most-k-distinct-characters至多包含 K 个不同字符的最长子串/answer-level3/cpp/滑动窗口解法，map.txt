class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int leftIndex = 0;
        int rightIndex = 0;
        int maxLen = 0;
        char tempCh1 = 0;
        char tempCh2 = 0;
        unordered_map<char, int>sliderWindow;
        
        while (rightIndex < s.size()) {
            tempCh1 = s[rightIndex];
            sliderWindow[tempCh1]++;
            rightIndex++;
            while (sliderWindow.size() > k) {
                tempCh2 = s[leftIndex];
                sliderWindow[tempCh2]--;

                if(sliderWindow[tempCh2] == 0) {        
                    sliderWindow.erase(tempCh2);  // erase用法需要熟悉
                }
                leftIndex++;
            }
            maxLen = max(maxLen, rightIndex - leftIndex);
        }
        return maxLen;
    }
};