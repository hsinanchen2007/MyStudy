 public void merge(int[] nums1, int m, int[] nums2, int n) {

        int  count = m;
        if (m == 0){
            for (int i = 0; i < n; i ++){
                nums1[i] = nums2[i];
            }
            return;
        }

        for (int i = 0; i < n; i ++){
            nums1[count ++] = nums2[i];
        }

        int record = 0; // 设置哨兵
        int j;
        for(int i = m; i < m +n ; i ++){
            record = nums1[i];
            j = i - 1;
            while (j >= 0 && record < nums1[j]){
                nums1[j + 1] = nums1[j];
                j = j - 1;
            }
            nums1[j + 1] = record;
        }
    }
