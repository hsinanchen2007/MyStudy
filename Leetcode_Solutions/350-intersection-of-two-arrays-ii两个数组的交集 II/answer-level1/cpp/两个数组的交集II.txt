// 思路：遍历数组1，以数组元素为键，map++；遍历数组2，发现map中有当前元素且个数>0，则存入结果数组，同时map--。

    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        map<int,int> m1;
        for(int iLoop=0;iLoop<nums1.size();iLoop++){
            m1[nums1[iLoop]]++;
        }
        for(int iLoop=0;iLoop<nums2.size();iLoop++){
            if(m1.count(nums2[iLoop])>0&&m1[nums2[iLoop]]>0){
                res.push_back(nums2[iLoop]);
                m1[nums2[iLoop]]--;
            }
        }
        return res;
    }

