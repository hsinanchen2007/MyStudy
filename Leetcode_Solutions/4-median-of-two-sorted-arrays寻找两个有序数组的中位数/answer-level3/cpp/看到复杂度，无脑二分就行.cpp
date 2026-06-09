class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double ans = 0.0f;
        if(!nums1.size() && !nums2.size())
            return ans;
        bool single = (nums1.size()+nums2.size())%2;
        if(!nums1.size()) {
            if(single) {
                ans = nums2[(nums2.size()-1)/2];
            } else {
                ans = nums2[(nums2.size()-1)/2]+nums2[(nums2.size())/2];
                ans /= 2;
            }
            return ans;
        }
        if(!nums2.size()) {
            if(single){
                ans = nums1[(nums1.size()-1)/2];
            } else {
                ans = nums1[(nums1.size()-1)/2]+nums1[(nums1.size())/2];
                ans /= 2;
            }
            return ans;
        }
        bool issucc = false;
        int pos = (nums1.size()+nums2.size()+1)/2;
        ans = findnum(nums1, nums2, pos, single, issucc);
        if(!issucc)
            ans = findnum(nums2, nums1, pos, single, issucc);
        return ans;
    }

    double findnum(vector<int>& nums1, vector<int>& nums2, int num, bool single, bool &issucc) {
        double ans = 0.0f;
        int L = 0;
        int R = nums1.size()-1;
        while(L <= R) {
            int Mid = (L+R)/2;
            int other = num-Mid-1;
            if(Mid >= num) {
                R = Mid-1;
            } else if(nums2.size() < other) {
                L = Mid+1;
            } else if(nums2.size() == other) {
                if(nums2[nums2.size()-1] <= nums1[Mid]) {
                    ans = nums1[Mid];
                    if(!single) {
                        ans += nums1[Mid+1];
                        ans /= 2;
                    }
                    issucc = true;
                    return ans;
                } else {
                    L = Mid+1;
                }
            } else {
                if(other == 0) {
                    if(nums2[0] >= nums1[Mid]) {
                        ans = nums1[Mid];
                        if(!single) {
                            if(Mid+1 >= nums1.size()) {
                                ans += nums2[0];
                            } else {
                                ans += std::min(nums2[0], nums1[Mid+1]);
                            }
                            ans /= 2;
                        }
                        issucc = true;
                        return ans;
                    } else {
                        R = Mid-1;
                    }
                } else {
                    if(nums2[other] >= nums1[Mid] && nums2[other-1] <= nums1[Mid]) {
                        ans += nums1[Mid];
                        if(!single) {
                            if(Mid+1 >= nums1.size()) {
                                ans += nums2[other];
                            } else {
                                ans += std::min(nums2[other], nums1[Mid+1]);
                            }
                            ans /= 2;
                        }
                        issucc = true;
                        return ans;
                    } else if(nums2[other] < nums1[Mid]) {
                        R = Mid-1;
                    } else {
                        L = Mid+1;
                    }
                }
            }
        }
        return ans;
    }
};