![360截图20200406225553666.jpg](https://pic.leetcode-cn.com/00c7191dc722132fdfbdb4cd9f4ac9de27bcd339b66554dbdee193a33a69c4d9-360%E6%88%AA%E5%9B%BE20200406225553666.jpg)


class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> res;
        vector<int> numss(nums);
        sort(numss.begin(),numss.end());
        for(int i = 0;i<numss.size();i++) {
           // res.push_back(     numss.find(nums[i])         );



            vector<int>::iterator it;
            it = find(numss.begin(),numss.end(),nums[i]);
            res.push_back(   &*it-&numss[0]);

        }
        return res;
        
    }
};