class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> :: size_type l1 = nums1.size();
        vector<int> :: size_type l2 = nums2.size();
        int pos = 0;
        double ans = 0.0;
        bool flag = false;
        if(l1 == 0)
        {
            if(l2 % 2 == 0)
            {
                double a1 = (double)nums2[l2 / 2 - 1];
                double a2 = (double)nums2[l2 / 2];
                return (a1 + a2) / 2;
            }
            else
            {
                return (double)nums2[l2 / 2];
            }
        }
        else if(l2 == 0)
        {
            if(l1 % 2 == 0)
            {
                double a1 = (double)nums1[l1 / 2 - 1];
                double a2 = (double)nums1[l1 / 2];
                return (a1 + a2) / 2;
            }
            else
            {
                return (double)nums1[l1 / 2];
            }
        }
        if((l1 + l2) % 2 == 0)
        {
            pos = (l1 + l2) / 2 - 1;
            flag = true;
        }
        else
        {
            pos = (l1 + l2) / 2; 
        }
        vector<int> :: iterator iteans;
        vector<int> :: iterator ite1 = nums1.begin();
        vector<int> :: iterator ite2 = nums2.begin();
        for(int j = 0; j < l1 + l2; ++j)
        {
            if(ite1 != nums1.end() && ite2 != nums2.end() &&
              *ite1 <= * ite2)
            {
                iteans = ite1;
                ++ite1;
            }
            else if(ite1 != nums1.end() && ite2 != nums1.end() &&
                   *ite1 > * ite2)
            {
                iteans = ite2;
                ++ite2;
            }
            else if(ite1 == nums1.end())
            {
                iteans = ite2;
                ++ite2;
            }
            else
            {
                iteans = ite1;
                ++ite1;
            }
            if(j == pos)
                break;
        }
        double a1 = (double)*iteans, a2 = 0.0;
        if(!flag)
            return a1;
        else
        {
            if((ite1 != nums1.end() && ite2 != nums2.end() &&
              *ite1 <= *ite2) || ite2 == nums2.end())
            {
                a2 = (double)*ite1;
            }
            else
                a2 = (double)*ite2;
            return (a1 + a2) / 2;
        }
    }
};