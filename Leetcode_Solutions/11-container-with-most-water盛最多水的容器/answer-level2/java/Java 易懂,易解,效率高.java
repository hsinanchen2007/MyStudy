**1.官方：我们试图将指向较长线段的指针向内侧移动，矩形区域的面积将受限于较短的线段而不会获得任何增加。但是，在同样的条件下，移动指向较短线段的指针尽管造成了矩形宽度的减小，但却可能会有助于面积的增大。因为移动较短线段的指针会得到一条相对较长的线段，这可以克服由宽度减小而引起的面积减小。
2.以上是官方的说法,通俗易懂,简单来讲:短指针(指向元素值较小的指针)每次向中间移动;
3.完结。**

        public int maxArea(int[] height) {
            int max = 0, l = 0, r = height.length - 1;
            while (l < r) {
                max = Math.max(max, Math.min(height[l], height[r]) * (r - l));
                if (height[l] < height[r])
                    l++;
                else
                    r--;
            }
            return max;
        }