  public int firstBadVersion(int n) {
    int left=1,right=n;//第一个和最后一个
      while(left<right){
          int mid=left+(right-left)/2;//二分查找法，找到mid
          if(isBadVersion(mid)){
              right=mid;//调用接口以后如果有错误就把错误的那个给right
          }else{
              left=mid+1;//如果没有问题就缩小范围继续排查
          }
      }
      return right;
}