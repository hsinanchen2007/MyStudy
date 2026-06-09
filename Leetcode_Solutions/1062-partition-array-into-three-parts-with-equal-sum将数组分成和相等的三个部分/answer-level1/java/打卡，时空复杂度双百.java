    // 如果返回true，必定有 x + x + x = sum，能被三整除
    // 求出左边和为x的序列后，再看右边是否有两个和为x的序列
    class Solution {
        public boolean canThreePartsEqualSum(int[] A) {
            int sum = 0;
            for(int i = 0;i < A.length;i++) {
                sum += A[i];
            }
            if(sum % 3 != 0) {
                return false;
            }
            int left = 0;
            for(int i = 0;i < A.length;i++) {
                left += A[i];
                if(sum / 3 == left) {
                    for(int j = i + 1, right = 0;j < A.length;j++) {
                        right += A[j];
                        if(right == left && j < A.length - 1) {
                            return true;
                        }
                    }
                }
            }
            return false;
        }
    }