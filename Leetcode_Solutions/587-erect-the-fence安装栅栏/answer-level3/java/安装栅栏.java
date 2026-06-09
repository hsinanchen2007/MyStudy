#### 方法 1： Jarvis 算法 [Accepted]

**算法**

Jarvis 算法背后的想法非常简单。我们从给定点集中最左边的点开始，按逆时针方向考虑将所有给定点包围起来的边界点。

这意味着对每一个点 $p$，我们试图找到一个点 $q$，满足点 $q$ 是所有点中相对于 $p$ 点逆时针方向最近的点。为了找到点 $q$，我们使用函数 `orientation()`，这个函数有 3 个参数，分别是当前凸包上的点 $p$，下一个会加到凸包里的点 $q$，其他点空间内的任何一个点 $r$。如果 $q$ 点相对于 $r$ 点来说在点 $p$ 的逆时针方向上的话，这个函数返回一个负值。

下图说明了这样的关系，点 $q$ 相比点 $r$ 在点 $p$ 的逆时针方向上。

![image.png](https://pic.leetcode-cn.com/047b7ce0d1fba3362cc01527bdf61f57f9a22c1ee3b5f063bbf08037b2ae3929-image.png)
{:align="center"}


从上图中，我们可以观察到点 $p$，$q$ 和 $r$ 形成的向量相应地都是逆时针方向，向量 $\vec{pq}$ 和 $\vex{qr}$ 的方向都朝平面向外，也就是是个正值。

$$\vec{pq}\ \times\ \vec{qr} > 0$$

$$\begin{vmatrix} (q_x-p_x) & (q_y-p_y) \\ (r_x-q_x) & (r_y-p_y) \end{vmatrix} > 0$$

$$(q_x - p_x)*(r_y - q_y) - (q_y - p_y)*(r_x - q_x) > 0$$

$$(q_y - p_y)*(r_x - q_x) - (r_y - q_y)*(q_x - p_x) < 0$$

上面的结果通过函数 `orientation()` 计算。

我们遍历所有点 $r$，找到相对于点 $p$ 来说逆时针方向最靠外的点 $q$，把它加入凸包。进一步的，如果存在 2 个点相对点 $p$ 在同一条线上，我们使用 `inBetween()` 函数，将 $q$ 和 $p$ 同一线段上的边界点都考虑进来。

通过这样，我们不断将凸包上的点加入，直到回到了开始的点。

下面的动图描述了该过程。

<![image.png](https://pic.leetcode-cn.com/db7030a438bfd419177d9493eaa12a3ebe1b60fb96e272160e18b4a41929b497-image.png),![image.png](https://pic.leetcode-cn.com/f3a65640532221fe2329e342b61f051ac7cef5c1a368fa7c885ddfde486a4721-image.png),![image.png](https://pic.leetcode-cn.com/b52f843468ac552d0ddbac1681522681abd3624b853737ea5f6ce1afdab667da-image.png),![image.png](https://pic.leetcode-cn.com/15d9b8397a6bf5d326858b119f831c458ab48d393488c64685062f8d579cf347-image.png),![image.png](https://pic.leetcode-cn.com/056968ffc825aed329c2d344fa28c777bcff8615dea6ddbad7813a993175feb2-image.png),![image.png](https://pic.leetcode-cn.com/16d6023e5f89aa8d3499fbfe974b27f4caf64e9c20ae7c0c4386ca3d7fc0b11c-image.png),![image.png](https://pic.leetcode-cn.com/343585c8d16e4abaaeeefedbb57a3820762c9577a05cc2c5fec3bbcef119a121-image.png),![image.png](https://pic.leetcode-cn.com/aa5924db788a6a3fa20dc63a19b3d7a3c5bb8b8eef375d48aff8c6d0e95b296e-image.png),![image.png](https://pic.leetcode-cn.com/8e4bd1b9d69d705f2187e6c169eefcfa4abc7019506c3e60f5a44ef19213c6c1-image.png),![image.png](https://pic.leetcode-cn.com/399a63541b548c4cd9f197debdc1c7362078e3fad4f0898b759c398797143750-image.png),![image.png](https://pic.leetcode-cn.com/550847328561a1c37ab0db4aa35c3e3da6dee4b8ba22638cee2191fcc9fa5c16-image.png),![image.png](https://pic.leetcode-cn.com/625f1df9822c6e12cf2b5ad4f967472088321c630c2f9a7018e82aa406388726-image.png),![image.png](https://pic.leetcode-cn.com/a21dc54d90b030ebc6d109841b98c2d5593c9fcb2de2197d7b2a3a100b650aa5-image.png),![image.png](https://pic.leetcode-cn.com/64d7d4112f878b984be6f4732fce948c87412767de790b698a2891e3bf890270-image.png),![image.png](https://pic.leetcode-cn.com/72d3a4ff10f1badb60d4c09e337c1f66d94b114e0d6c003ee293ce4573192e56-image.png),![image.png](https://pic.leetcode-cn.com/015c1c0decd6417306bedab3db6720e736beaf39bc4ede41b505940a64494036-image.png),![image.png](https://pic.leetcode-cn.com/874a693996d6a7ce740570b1721c0bc166bb8e0be04f8d673877242f833a6afd-image.png),![image.png](https://pic.leetcode-cn.com/0a9a86cb949546ab33193f9c68809c2554c9c68a185886741cb37b5fc53273fb-image.png),![image.png](https://pic.leetcode-cn.com/e35b11e9191d9f0f5176755b52b7460991a8fd98b563e9952826f556ab20a6f7-image.png),![image.png](https://pic.leetcode-cn.com/e26909eafac7d617a0a0e4203ddd321ee9aae77000f4cc425518c69716aeff2a-image.png),![image.png](https://pic.leetcode-cn.com/28ba662f3cc1ac40e8b24b79f4aa76effce338d5e134e2b581dbadda02d1e22a-image.png),![image.png](https://pic.leetcode-cn.com/4ab5beeb3f98371e18c7d77e6d57a33c3ffa95358397550936b58ad53d275405-image.png),![image.png](https://pic.leetcode-cn.com/03e81cdf4ed3904307a7627a467eb9bfa6b5474883d0cd7bd7cfad20421a3756-image.png),![image.png](https://pic.leetcode-cn.com/261aa25835f941c885ca821b549bbf14d4773e3ab5b90e032a222bb07c09cde6-image.png),![image.png](https://pic.leetcode-cn.com/ae44a34d313948a85b807c4b71a2050f103514fa3acaa3b48857e83ea02241a2-image.png),![image.png](https://pic.leetcode-cn.com/5103dee9b8f9cee208547e3491256bca413fe03253cfe9ef8f287313eddcb9dc-image.png),![image.png](https://pic.leetcode-cn.com/607444e1a8b5d4fc8b829e11ea2569e5fe8395bcde794398b809bdb34b75df0a-image.png),![image.png](https://pic.leetcode-cn.com/94ea4758c1608e4ddea2ea18a1aa87e826a69fce9934fc58bd94eda6d04fe9c1-image.png),![image.png](https://pic.leetcode-cn.com/a3cd11faca8d9848776d865824663fbe035b4740c0cd7cdef7acf1591e6f030f-image.png),![image.png](https://pic.leetcode-cn.com/f81a1e0622218aa9303b7dde0f592d722cdea8bf5b2e50b5abf7bccb46b69b4c-image.png),![image.png](https://pic.leetcode-cn.com/36b5fc52ea2c5c3202351926519bfc386b9cfc6119eb5e2e02ec319ad4254ba9-image.png),![image.png](https://pic.leetcode-cn.com/d640ccd0b5854d0ca3d39b918d064f95ec0238b90380cc71fff3094f61f06a13-image.png),![image.png](https://pic.leetcode-cn.com/54497c55fc5d73df553d127ce2af568a70d45af9b37ea6efc8eaa0e7b9c97352-image.png),![image.png](https://pic.leetcode-cn.com/ffacf69ea27167317b3bf870be8b161d0a5de2eff4331f0f968776f039ee45fc-image.png),![image.png](https://pic.leetcode-cn.com/f8ea7e5cfe30beeddb61a9043313ae2fa12527dbb27ea4f24672e3dfb13db4a5-image.png),![image.png](https://pic.leetcode-cn.com/6e2b4ec2ea40533d6681c2d0e740b02dcf5654e6832d9fac7a4cce73f5b52e45-image.png),![image.png](https://pic.leetcode-cn.com/c2dc88dc15839687aa89a1ec39925f0652c5cb9ae72321f94607e0db2a25a792-image.png),![image.png](https://pic.leetcode-cn.com/7f6224f9aedf5ef8a17e56adc2e3918ee200695fe779e33679d4a2bae2691e2b-image.png),![image.png](https://pic.leetcode-cn.com/3b5002638f57a8c86e1f6d7b3b9e83f6f7406fe7193f2bfac8b175a8b9a4abeb-image.png),![image.png](https://pic.leetcode-cn.com/33e67ca6d4faaf4cf0005401f5d1d75e81e326c3e69090edff22c465f1c91d72-image.png)>

```Java []
public class Solution {
    public int orientation(Point p, Point q, Point r) {
        return (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    }
    public boolean inBetween(Point p, Point i, Point q) {
        boolean a = i.x >= p.x && i.x <= q.x || i.x <= p.x && i.x >= q.x;
        boolean b = i.y >= p.y && i.y <= q.y || i.y <= p.y && i.y >= q.y;
        return a && b;
    }
    public List < Point > outerTrees(Point[] points) {
        HashSet < Point > hull = new HashSet < > ();
        if (points.length < 4) {
            for (Point p: points)
                hull.add(p);
            return new ArrayList<Point>(hull);
        }
        int left_most = 0;
        for (int i = 0; i < points.length; i++)
            if (points[i].x < points[left_most].x)
                left_most = i;
        int p = left_most;
        do {
            int q = (p + 1) % points.length;
            for (int i = 0; i < points.length; i++) {
                if (orientation(points[p], points[i], points[q]) < 0) {
                    q = i;
                }
            }
            for (int i = 0; i < points.length; i++) {
                if (i != p && i != q && orientation(points[p], points[i], points[q]) == 0 && inBetween(points[p], points[i], points[q])) {
                    hull.add(points[i]);
                }
            }
            hull.add(points[q]);
            p = q;
        }
        while (p != left_most);
        return new ArrayList<Point>(hull);
    }
}
```

**复杂度分析**

* 时间复杂度： $O(m*n)$ 。对于凸包上的每一个点，我们需要检查所有其他的点来确定下一个在凸包上的点。这里 $n$ 是输入的点数， $m$ 是输出的点数（即凸包上的点数）。（$m \leq n$）。

* 空间复杂度： $O(m)$ 。列表 $hull$ 最多大小为 $m$ 。

#### 方法 2：Graham 扫描 [Accepted]

**算法**

Graham 算法也是一个给定点集找凸壳的标准算法。下面的动画说明了这一算法的过程。

<![image.png](https://pic.leetcode-cn.com/4547b1d7bec50f8f4abc83293be1e3b2fb88a8c7d8b7547f271c120551889fa3-image.png),![image.png](https://pic.leetcode-cn.com/3e38405a62705e79b50e2a84c9d629eaf650679cf045c7c27790ab9eabdac3de-image.png),![image.png](https://pic.leetcode-cn.com/7fec73962fd9ff12c096dcaf29c99218ab853cf6e930832616fb8eafe1d0cb97-image.png),![image.png](https://pic.leetcode-cn.com/0ac5b63afb23c200adbe27c1efbf6d43f43d349159a910d13c53913465ce88c1-image.png),![image.png](https://pic.leetcode-cn.com/cbf252cb894aba0bd58124688412aea04b0e461cf503b2204a433fdfee782f2a-image.png),![image.png](https://pic.leetcode-cn.com/8ddd88947a93f38a335423673e3cd5f607c8c08411b6a3ca140b3039a4a91b9c-image.png),![image.png](https://pic.leetcode-cn.com/315fa316991f206b2089c6510d2816c6d39eab7452c35f0963ecb9ba0540941c-image.png),![image.png](https://pic.leetcode-cn.com/2e97f05bbf869b9a97d6ce58258b81bbc38bffe1916abafee706c9af4c1bb0aa-image.png),![image.png](https://pic.leetcode-cn.com/0dd30c7de47dd8c8eaa4840a8c041fc28896742d114f082d90a3c26929a49e5d-image.png),![image.png](https://pic.leetcode-cn.com/c1523a37b29cd82f7bac54d63b60f30a4cd0c9a18e531088a1d7bf5542ea8a96-image.png),![image.png](https://pic.leetcode-cn.com/333d052e9dfb09dd18de65ab0b7c14028c6f1defbe69fe42afc323427885ba8d-image.png),![image.png](https://pic.leetcode-cn.com/d0052ff5ece576abeeedfd89a87d0d2b7632437420e302f6d9da79b91fe5170c-image.png),![image.png](https://pic.leetcode-cn.com/3531af674b97d4f2947c7c1666655a1b206b1c998759e9059611a4a1c219d23f-image.png),![image.png](https://pic.leetcode-cn.com/3b18152d25ba1fcd0c4e32782b8a6a8c4384f5a92105d37e2952f72b78290738-image.png),![image.png](https://pic.leetcode-cn.com/ceceb5b93684bbd31ddc4abde6e069196a0a4868526ca7d6819732f7cb112d07-image.png)>

这个方法的具体实现为：首先选择一个凸包上的初始点 $bm$ 。我们选择 y 坐标最小的点为起始点，如果有相同的最小 y 坐标，我们选择 x 坐标最小的，这个点被记为动图中的点 0 。然后我们将给定点集按照相对初始点的极角坐标排序（也就是从点 0 出发的一条直线）。

这一排序过程大致给了我们在逆时针顺序选点时候的思路。为了将点排序，我们使用上一方法使用过的函数 `orientation` 。极角顺序更小的点排在数组的前面。如果有两个点相对于点 0 在同一方向上，我们将它们按照与点 0 的距离排序。

我们还需要考虑另一种重要的情况，如果共线的点在凸壳的最后一条边上，我们需要从距离初始点最远的点开始考虑起。所以，在将数组排序后，我们从尾开始遍历有序数组并将共线且朝有序数组尾部的点反转顺序，因为这些点是形成凸壳过程中尾部的点，所以在经过了这些处理以后，我们得到了求凸壳时正确的点的顺序。

现在我们从有序数组最开始两个点开始考虑。我们将这条线上的点放入栈中。然后我们从第三个点开始遍历有序数组 $points$ 。如果当前点与栈顶的点相比前一条线是一个“左拐”或者是同一条线段上，我们都将当前点添加到栈顶，表示这个点暂时被添加到凸壳上。

检查左拐或者右拐使用的还是 `orientation` 函数。如果函数返回值大于 0 ，这表示当前点与栈顶点与上一条线之间的关系是逆时针的（即右拐的）。类似的，如果函数返回值是负数，表示是左拐。

如果当前点与上一条线之间的关系是右拐的，说明上一个点不应该被包括在凸壳里，因为它在边界的里面（正如动画中点 4 ）。所以我们将它从栈中弹出并考虑倒数第二条线的方向。

重复这一过程，弹栈的操作会一直进行，直到我们当前点在凸壳中出现了右拐。这表示这时凸壳中只包括边界上的点而不包括边界以内的点。在所有点被遍历了一遍以后，栈中的点就是构成凸壳的点。

```Java []
public class Solution {
    public int orientation(Point p, Point q, Point r) {
        return (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    }
    public int distance(Point p, Point q) {
        return (p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y);
    }
    private static Point bottomLeft(Point[] points) {
        Point bottomLeft = points[0];
        for (Point p: points)
            if (p.y < bottomLeft.y)
                bottomLeft = p;
        return bottomLeft;
    }
    public List < Point > outerTrees(Point[] points) {
        if (points.length <= 1)
            return Arrays.asList(points);
        Point bm = bottomLeft(points);
        Arrays.sort(points, new Comparator < Point > () {
            public int compare(Point p, Point q) {
                double diff = orientation(bm, p, q) - orientation(bm, q, p);
                if (diff == 0)
                    return distance(bm, p) - distance(bm, q);
                else
                    return diff > 0 ? 1 : -1;
            }
        });
        int i = points.length - 1;
        while (i >= 0 && orientation(bm, points[points.length - 1], points[i]) == 0)
            i--;
        for (int l = i + 1, h = points.length - 1; l < h; l++, h--) {
            Point temp = points[l];
            points[l] = points[h];
            points[h] = temp;
        }
        Stack < Point > stack = new Stack < > ();
        stack.push(points[0]);
        stack.push(points[1]);
        for (int j = 2; j < points.length; j++) {
            Point top = stack.pop();
            while (orientation(stack.peek(), top, points[j]) > 0)
                top = stack.pop();
            stack.push(top);
            stack.push(points[j]);
        }
        return new ArrayList < > (stack);
    }
}
```

**复杂度分析**

* 时间复杂度： $O\big(nlog(n)\big)$。将给定点排序需要花费 $O\big(nlog(n)\big)$ 的时间。进一步的，在排序以后，每个点会在两种情况中被考虑到，分别是压栈和弹栈的过程。所以每个点最多会被访问 2 次，最坏情况下要 $2n$ ($O(n)$) 的时间。

* 空间复杂度：$O(n)$。最坏情况下栈的大小为 $n$。

#### 方法 3：单调链 [Accepted]

**算法**

单调链算法的想法与 Graham 扫描算分类似。它们主要的不同点在于凸壳上点的顺序。与 Graham 扫描算法按照点计较顺序排序不同，我们按照点的 x 坐标排序。如果两个点又相同的 x 坐标，那么就按照它们的 y 坐标排序。背后的原因稍后会做解释。

在这个算法中，我们将凸壳考虑成 2 个子边界组成：上凸壳和下凸壳。我们处理这两部分时略有不同。

我们首先将最初始的两个点添加到凸壳中，然后遍历排好序的 $points$ 数组。对于每个新的点，我们检查当前点是否在最后两个点的逆时针方向上。如果是的话，当前点直接被压入凸壳 $hull$ 中，如果不是的话（即 `orientation` 返回的结果为正数），我们可以知道栈顶的元素在凸壳里面而不是凸壳边上。我们继续从 $hull$ 中弹出元素直到当前点相对于栈顶的两个点的逆时针方向上。

这个方法中，我们不需要显式地考虑共线的点，因为这些点已经按照 x 坐标排好了序。所以如果有共线的点，它们已经被隐式地按正确顺序考虑了。

通过这样，我们会一直遍历到 x 坐标最大的点为止。但是凸壳还没有完全求解出来。目前求解出来的部分只包括凸壳的下半部分。现在我们需要求出凸壳的上半部分。

我们继续找下一个逆时针的点并将不在边界上的点从栈中弹出，但这次我们遍历的顺序是按照 x 坐标从大到小，我们只需要从后往前遍历有序数组 $points$ 即可。我们将新的上凸壳的值添加到之前的 $hull$ 数组中。最后，$hull$ 数组返回了我们需要的边界上的点。

下面的动图展示了这一过程。

<![image.png](https://pic.leetcode-cn.com/28c74c05c7e71763df6778647b202c8467464d528e2c24b56d4800c44e50ec8a-image.png),![image.png](https://pic.leetcode-cn.com/c9e083c99971d9c31eb284d55bc3e180fdac2cd16a15c33c098606aa04eaeb97-image.png),![image.png](https://pic.leetcode-cn.com/ffe6085c21d3e0925fa22183bb48b92471eb0b95894423523473a446a7403321-image.png),![image.png](https://pic.leetcode-cn.com/eca3df66fca58cc2baa18ecf14b9ccd957b352aaed6c32d4a4ee5f968d71a916-image.png),![image.png](https://pic.leetcode-cn.com/f45b8abcf52700532893947c88c19ee04918138ac7aaa8f033e0e65a52d23826-image.png),![image.png](https://pic.leetcode-cn.com/11a7379c6abe2a1cbfa23252ecf95c634248e53531a876628c4f3ab3d8db5df5-image.png),![image.png](https://pic.leetcode-cn.com/012f30834de8c581a921d4142003bb7ef243f66f035ce716ea0e24dd56ca0c59-image.png),![image.png](https://pic.leetcode-cn.com/9370c1061b17940996c03ea90dd4165982dc2acd36dd4daa4560982f4a0bc230-image.png),![image.png](https://pic.leetcode-cn.com/e030f2b0448b528604e85d9f17f4d1fd4a679d9e3b60bb37706034b7abca2a0a-image.png),![image.png](https://pic.leetcode-cn.com/cccf8a43fd9424cba7ab476f362ef28c4dd27566950c8076e8034c2496b21857-image.png),![image.png](https://pic.leetcode-cn.com/6692d870df81f3c1338e297449122abeb008e92f9edd47949467c69acb6294f8-image.png),![image.png](https://pic.leetcode-cn.com/57c03e527887ade079669b3c9c58f9b104701a41c9bea2f34ae95de246be702c-image.png),![image.png](https://pic.leetcode-cn.com/90eb1c164ed398fdbddf1dd23239902a605cff02c61c35ca8f33168573cff80b-image.png),![image.png](https://pic.leetcode-cn.com/5155cb152972a7bd6ffc67bb1f7713cc98e98a46aaeb2eb09be676105f70bb6b-image.png),![image.png](https://pic.leetcode-cn.com/789246c4139c7bb3634734b2e2fc2aa4584322584509c49129d1300adcb8d888-image.png),![image.png](https://pic.leetcode-cn.com/3afed0d6c7a2453a09379f97791eeaf45d469f1e2b21ba65b377142ab4500cc3-image.png),![image.png](https://pic.leetcode-cn.com/77c766fe39fef45549e1149954bf5b717cdd7d9f34caa1def01764234c79677d-image.png),![image.png](https://pic.leetcode-cn.com/617f5d0ff37692e9443aa2b02f2a3de6cac8e64a2c4d0fd6cc994ec7533662b2-image.png),![image.png](https://pic.leetcode-cn.com/4c02b60a2fa2bb8bfa9c60ff983ba76990e944ef3de41d85db61e9133ddf4742-image.png),![image.png](https://pic.leetcode-cn.com/419552b1b3adeb30d79f63c73faf742c1803ab4dee018e161102868b51795563-image.png),![image.png](https://pic.leetcode-cn.com/8391689b56933450bcf6b37d215071ccd50ac1ff5bcde193eedbfe6aa81d58fe-image.png),![image.png](https://pic.leetcode-cn.com/2475ed0aaaa5531d28214fd8ecd521e0b6fbed06b45f24ddecbc70a70169ef39-image.png),![image.png](https://pic.leetcode-cn.com/4177c35db6be3faa7d9c9eef61ac4bf7a669da8179412f7ab675e2a3728cce51-image.png),![image.png](https://pic.leetcode-cn.com/af71dc94c4459577aa65b775c94ef7bc2affbdd7b1f29926cae31a7d05ee0dfb-image.png),![image.png](https://pic.leetcode-cn.com/1332b23ab751058b102ec1b1726ee6aae196b2c89fd2c0fe5b4fce5ba239097f-image.png),![image.png](https://pic.leetcode-cn.com/444083192d672e1aa13c1c52d57dc106ba244a3b6879432fe76c0e89a76edc18-image.png),![image.png](https://pic.leetcode-cn.com/afece179c0208fd75de069336e5ca927fc20a4825a7a6f840009565cc0febd74-image.png),![image.png](https://pic.leetcode-cn.com/15ecfd82ca2e53fb57b9c69a308a8879477e7c64ed91705dbd3ffc7b8f8a3786-image.png),![image.png](https://pic.leetcode-cn.com/9a9ea7becb0a58da8589c78b6e087fdbf555f7e94dc5bf9441fadca352287f74-image.png)>

```Java []
public class Solution {
    public int orientation(Point p, Point q, Point r) {
        return (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    }
    public List < Point > outerTrees(Point[] points) {
        Arrays.sort(points, new Comparator < Point > () {
            public int compare(Point p, Point q) {
                return q.x - p.x == 0 ? q.y - p.y : q.x - p.x;
            }
        });
        Stack < Point > hull = new Stack < > ();
        for (int i = 0; i < points.length; i++) {
            while (hull.size() >= 2 && orientation(hull.get(hull.size() - 2), hull.get(hull.size() - 1), points[i]) > 0)
                hull.pop();
            hull.push(points[i]);
        }
        hull.pop();
        for (int i = points.length - 1; i >= 0; i--) {
            while (hull.size() >= 2 && orientation(hull.get(hull.size() - 2), hull.get(hull.size() - 1), points[i]) > 0)
                hull.pop();
            hull.push(points[i]);
        }
        return new ArrayList < > (new HashSet < > (hull));
    }
}
```

**复杂度分析**

* 时间复杂度：$O\big(nlog(n)\big)$。将给定点集排序需要 $O\big(nlog(n)\big)$ 的时间。进一步的，排序后的点会在两种情况下遍历到，一次是压入栈中，另一次是弹出栈。每个点最多会被遍历 2 次，最坏情况下时间复杂度为 $2n$($O(n)$)。

* 空间复杂度：$O(n)$。栈 $hull$ 大小最多为 $n$。
