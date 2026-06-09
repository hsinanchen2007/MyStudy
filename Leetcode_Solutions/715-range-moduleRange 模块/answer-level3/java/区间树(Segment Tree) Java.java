```
class RangeModule {

  private class SegmentTree {

    int start, end;
    SegmentTree ls, rs;
    boolean isLazy;
    int sum;

    public SegmentTree(int start, int end, SegmentTree ls, SegmentTree rs, int sum) {
      this.start = start;
      this.end = end;
      this.ls = ls;
      this.rs = rs;
      this.sum = sum;
      this.isLazy = false;
    }

    private void addRange(int left, int right, boolean remove) {
      if (left > right) {
        return;
      }
      if (start >= left && end <= right) {
        isLazy = true;
        sum = remove ? 0 : right - left + 1;
        return;
      }
      int middle = start + ((end - start) >> 1);
      if (ls == null) {
        ls = new SegmentTree(start, middle, null, null, 0);
      }
      if (rs == null) {
        rs = new SegmentTree(middle + 1, end, null, null, 0);
      }
      pushDown();
      if (middle >= right) {
        ls.addRange(left, right, remove);
      } else if (middle < left) {
        rs.addRange(left, right, remove);
      } else {
        ls.addRange(left, middle, remove);
        rs.addRange(middle + 1, right, remove);
      }
      sum = ls.sum + rs.sum;
    }

    private void pushDown() {
      if (!isLazy) {
        return;
      }
      isLazy = false;
      if (sum == 0) {
        ls.sum = 0;
        ls.isLazy = true;
        rs.sum = 0;
        rs.isLazy = true;
      } else {
        ls.sum = ls.end - ls.start + 1;
        ls.isLazy = true;
        rs.sum = rs.end - rs.start + 1;
        rs.isLazy = true;
      }
    }

    private int queryRange(int left, int right) {
      if (left > right) {
        return 0;
      }
      if (start >= left && end <= right) {
        return sum;
      }
      int middle = start + ((end - start) >> 1);
      if (ls == null) {
        ls = new SegmentTree(start, middle, null, null, 0);
      }
      if (rs == null) {
        rs = new SegmentTree(middle + 1, end, null, null, 0);
      }
      pushDown();
      if (middle >= right) {
        return ls.queryRange(left, right);
      } else if (middle < left) {
        return rs.queryRange(left, right);
      } else {
        return ls.queryRange(left, middle) + rs.queryRange(middle + 1, right);
      }
    }
  }

  private SegmentTree root;

  public RangeModule() {
    root = new SegmentTree(0, (int) 1e9, null, null, 0);
  }

  public void addRange(int left, int right) {
    root.addRange(left, right - 1, false);
  }

  public boolean queryRange(int left, int right) {
    return root.queryRange(left, right - 1) == right - left;
  }

  public void removeRange(int left, int right) {
    root.addRange(left, right - 1, true);
  }
}

/**
 * Your RangeModule object will be instantiated and called as such: RangeModule obj = new
 * RangeModule(); obj.addRange(left,right); boolean param_2 = obj.queryRange(left,right);
 * obj.removeRange(left,right);
 */
```