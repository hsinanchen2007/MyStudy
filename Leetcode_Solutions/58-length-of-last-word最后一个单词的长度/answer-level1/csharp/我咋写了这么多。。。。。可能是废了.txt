```
public class Solution {
    public int LengthOfLastWord(string s) {
        if(s == "") return 0;
        int NotKongGeNum = 0;
        List<int> nums = new List<int>();
        for(int i =0; i<s.Length;i++)
        {
            if(s[i] != ' ')
            {
                NotKongGeNum++;
            }
            else{
                if(NotKongGeNum!=0){
                     nums.Add(NotKongGeNum);
                }
                NotKongGeNum = 0;
            }
        }
        if(NotKongGeNum!=0)
        nums.Add(NotKongGeNum);
        if(nums.Count == 0) return 0;
        return nums[nums.Count-1];
    }
}
```
