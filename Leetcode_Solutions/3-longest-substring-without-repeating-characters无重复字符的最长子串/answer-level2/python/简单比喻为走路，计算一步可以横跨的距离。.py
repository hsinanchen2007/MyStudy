
用到set，set中包含动左腿，不包含动就右腿。

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        max = tmpMax = 0;
        mySet = set();
        leftLeg=rightLeg=0
        for x in s:
            while x in mySet:
                mySet.remove(s[leftLeg])
                leftLeg += 1
            rightLeg += 1
            tmpMax = rightLeg - leftLeg;
            if tmpMax > max: max = tmpMax
            mySet.add(x)
        return max

