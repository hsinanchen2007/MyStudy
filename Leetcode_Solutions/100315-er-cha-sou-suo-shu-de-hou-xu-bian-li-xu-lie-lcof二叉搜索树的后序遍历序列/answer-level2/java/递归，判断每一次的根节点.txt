    public boolean verifyPostorder(int[] postorder) {
        if (postorder == null || postorder.length == 0)
            return true;
        return verify(postorder, 0, postorder.length - 1);
    }

    private boolean verify(int[] postorder, int start, int end){
        if (start >= end)
            return true;
            
        int mid = 0;
        while (postorder[mid] < postorder[end])
            mid++;
        for (int i = mid; i < end; i++){
            if (postorder[i] < postorder[end])
                return false;
        }
        return verify(postorder, start, mid - 1) && verify(postorder, mid, end - 1);
    }