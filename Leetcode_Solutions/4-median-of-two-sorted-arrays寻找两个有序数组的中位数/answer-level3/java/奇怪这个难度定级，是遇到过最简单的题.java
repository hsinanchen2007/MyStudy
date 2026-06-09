    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int[] source = new int[nums1.length + nums2.length];
        System.arraycopy(nums1, 0, source, 0, nums1.length);
        System.arraycopy(nums2, 0, source, nums1.length, nums2.length);
        Arrays.sort(source);
        if (source.length % 2 == 0) {
            int tmp = source.length / 2;
            return (double) (source[tmp - 1] + source[tmp]) / 2;
        } else {
            return source[source.length / 2];
        }
    }