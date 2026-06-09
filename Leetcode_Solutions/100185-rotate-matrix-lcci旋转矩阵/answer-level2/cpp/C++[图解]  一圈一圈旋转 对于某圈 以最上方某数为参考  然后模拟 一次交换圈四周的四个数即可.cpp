```
    void rotate(vector<vector<int>>& a) {
        int n = a.size();
        for(int len = n; len >= 2; len -=2){//从外到内 一圈一圈的旋转90° len为当前圈的边长
            for(int cnt = 0; cnt < len-1; cnt++){//该交换当前圈最上方的第cnt个数 一次交换圈四周的四个数即可
                int i = (n-len)/2,j = (n-len)/2;//圈的左上角的下标
                swap(a[i][j+cnt],a[i+len-1-cnt][j]);//上和左交换
                swap(a[i+len-1-cnt][j],a[i+len-1][j+len-1-cnt]);//左和下交换
                swap(a[i+len-1][j+len-1-cnt],a[i+cnt][j+len-1]);//下和右交换
            }
        }
    }
```
对于边长为len的圈 画图很容易看出坐标变换的关系
![旋转.jpg](https://pic.leetcode-cn.com/fde10ebe6fb3f94836d8241face48d8cd9708c82451f3a04404fca451bd16da7-%E6%97%8B%E8%BD%AC.jpg)


