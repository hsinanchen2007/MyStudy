    // 栈深度挨着的要分开，用奇偶分开即可，这样A串B串深度最均匀
    class Solution {
        public int[] maxDepthAfterSplit(String seq) {
            int[] res = new int[seq.length()];
            int depth = 0;
            for(int i = 0;i < seq.length();i++) {
                if(seq.charAt(i) == '(') {
                    depth++;
                    res[i] = depth % 2;
                }else {
                    res[i] = depth % 2;
                    depth--;
                }
            }
            return res;
        }
    }