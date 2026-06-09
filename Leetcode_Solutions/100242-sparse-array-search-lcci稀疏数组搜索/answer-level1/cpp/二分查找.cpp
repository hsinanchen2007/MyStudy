二分查找简单变化一下即可。


```
class Solution {
   public:
    int findString(vector<string>& words, string s) {
        return find(words, s, 0, words.size() - 1);
    }

   private:
    int find(vector<string>& words, string s, int left, int right) {
        // 去除首尾是空字符
        while (left < right && words[left] == "") left++;
        while (left < right && words[right] == "") right--;
        if (left > right || (left == right && words[left] == "")) return -1;

        int mid = left + (right - left) / 2;
        int i = mid;

        // 先查找左边
        while (left < i && words[i] == "") i--;
        if (words[i] == s)
            return i;
        else if (words[i] > s)
            return find(words, s, left, i - 1);

        // 可能出现在右边
        i = mid;
        while (i < right && words[i] == "") i++;
        if (words[i] == s)
            return i;
        else if (words[i] < s)
            return find(words, s, i + 1, right);

        return -1;
    }
};

```
