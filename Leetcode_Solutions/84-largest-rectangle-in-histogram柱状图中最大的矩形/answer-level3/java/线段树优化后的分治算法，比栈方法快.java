    class Solution {
        private class SegmentTree {
            private int[] arr;
            private int[] tree;

            public SegmentTree(int[] arr) {
                this.arr = new int[arr.length];
                for (int i = 0; i < arr.length; i++) {
                    this.arr[i] = arr[i];
                }
                this.tree = new int[arr.length * 4];
                build();
            }

            private void build() {
                __build(0, 0, arr.length - 1);
            }

            private void __build(int index, int left, int right) {
                if (left > right)
                    return;

                if (left == right) {
                    this.tree[index] = left;
                    return;
                }

                int min = left;
                for (int i = left; i <= right; i++) {
                    if (this.arr[i] < this.arr[min])
                        min = i;
                }
                this.tree[index] = min;

                int mid = left + (right - left) / 2;
                __build(index * 2 + 1, left, mid);
                __build(index * 2 + 2, mid + 1, right);
            }

            private int get(int left, int right) {
                return __get(0, 0, arr.length - 1, left, right);
            }

            private int __get(int index, int left, int right, int searchLeft, int searchRight) {
                if (left == searchLeft && right == searchRight)
                    return this.tree[index];

                int mid = left + (right - left) / 2;
                if (left <= searchLeft && mid >= searchRight && left <= mid)
                    return __get(index * 2 + 1, left, mid, searchLeft, searchRight);
                if (mid + 1 <= searchLeft && right >= searchRight && mid + 1 <= right)
                    return __get(index * 2 + 2, mid + 1, right, searchLeft, searchRight);
                int index1 = searchLeft, index2 = searchLeft;
                if (left <= mid)
                    index1 = __get(index * 2 + 1, left, mid, searchLeft, mid);
                if (mid + 1 <= right)
                    index2 = __get(index * 2 + 2, mid + 1, right, mid + 1, searchRight);
                return this.arr[index1] < this.arr[index2] ? index1 : index2;
            }
        }

        private SegmentTree tree;
        private int[] heights;
        
        public int largestRectangleArea(int[] heights) {
            this.heights = heights;
            this.tree = new SegmentTree(heights);
            return __largestRectangleArea(0, heights.length - 1);
        }

        private int __largestRectangleArea(int left, int right){
            if (left > right)
                return 0;
            int index = tree.get(left, right);
            return Math.max(this.heights[index] * (right - left + 1), 
                    Math.max(__largestRectangleArea(left, index - 1), __largestRectangleArea(index + 1, right)));

        }
    }