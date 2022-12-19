如果匹配的话，假设word =  "abcd",分别对应在原数组中出现的索引为index1、index2、index3、index4,必须满足index1 < index2 < index3 < index4。问题转化为对于word中每个出现的字符，判断是否存在合适的索引满足上述要求。

首先保存每个S中每个字符出现的位置，需要注意这个位置是有序的（小-->大），所以查找合适的索引的时候可以用二分法。

```swift
class Solution {
    var charToIndices = Array<Array<Int>>(repeating: Array<Int>(), count: 26)
    let charToIndex: [Character:Int] = ["s": 18, "a": 0, "z": 25, "w": 22, "q": 16, "i": 8, "k": 10, "n": 13, "r": 17, "x": 23, "m": 12, "g": 6, "t": 19, "b": 1, "p": 15, "u": 20, "d": 3, "o": 14, "j": 9, "l": 11, "h": 7, "y": 24, "f": 5, "v": 21, "c": 2, "e": 4]
    func numMatchingSubseq(_ S: String, _ words: [String]) -> Int {
        let SToInt = S.map{ charToIndex[$0]!}
        for i in 0..<S.count {
            charToIndices[SToInt[i]].append(i)
        }
        var ans = 0
        for word in words {
            let wordToInt = word.map{charToIndex[$0]!}
            if match(wordToInt) {
                ans += 1
            }
        }
        return ans
    }
    private func match(_ word: [Int]) -> Bool {
        var maxIndex = -1
        var index = 0
        while index < word.count {
            var left = 0
            let indices = charToIndices[word[index]]
            var right = indices.count
            while left < right {
                let mid = left + (right - left) >> 1
                if indices[mid] > maxIndex {
                    right = mid
                } else if indices[mid] < maxIndex {
                    left = mid + 1
                } else {
                    left = mid + 1
                    break
                }
            }
            if left == indices.count {
                return false
            }
            if index == word.count - 1  {
                return true
            }
            maxIndex = indices[left]
            index += 1
        }
        return false
    }
}
```
```cpp
class Solution {
private :
    vector<vector<int >> charToIndices = vector<vector<int >>(26, vector<int>());
public:
    int numMatchingSubseq(string S, vector<string> &words) {
        for (int i = 0; i < S.length(); ++i) {
            charToIndices[S[i] - 'a'].push_back(i);
        }
        int ans = 0;
        for(auto word: words){
            vector<int > wordToInt = vector<int >(word.length(),0);
            for (int i = 0; i < word.length(); ++i) {
                wordToInt[i] = word[i] - 'a';
            }
            if(match(wordToInt)) {
                ans += 1;
            }
        }
        return ans;
    }

private:
    bool match(vector<int> &word) {

        int maxIndex = -1;
        int index = 0;
        int wordLength = word.size();
        while (index < wordLength) {
            int indicesLength = charToIndices[word[index]].size();
            int left = 0;
            int right = indicesLength;

            while (left < right) {
                int mid = (left + right) >> 1;
                if (charToIndices[word[index]][mid] > maxIndex) {
                    right = mid;
                } else if (charToIndices[word[index]][mid] < maxIndex) {
                    left = mid + 1;
                } else {
                    left = mid + 1;
                    break;
                }
            }
            if (left == indicesLength) {
                return false;
            }
            if (index == wordLength - 1) {
                return true;
            }
            maxIndex = charToIndices[word[index]][left];
            index += 1;
        }
        return false;
    }
};
```
