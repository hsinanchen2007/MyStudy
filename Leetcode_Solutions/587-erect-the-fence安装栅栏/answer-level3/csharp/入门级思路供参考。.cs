
   public class Solution
    {
        public int[][] OuterTrees(int[][] points)
        {
            var newList = new List<int[]>();
            //二维排序
            List<int[]> xyList = TwoDimensionXY(points);
            var left = xyList.Where(c => c[0] == xyList[0][0]).ToList();
            var topPoint = left[left.Count - 1];
            var bottomPoint = left[0];
            //左侧点纳入。
            newList.AddRange(left);
            //设定上顶点取正切最大值，
            GetFenchTop(newList,topPoint,xyList);
            //设定下顶点取正切最小值，
            GetFenchBottom(newList, bottomPoint, xyList);
            //去重
            return (Thin(newList));
        }

        private static void GetFenchTop(List<int[]> newList, int[] topPoint, List<int[]> xyList)
        {
            var tan = 0.0;
            var rightTopPoints = xyList.Where(c => c[0] > topPoint[0]).ToList();
            
            if (rightTopPoints.Count != 0 && rightTopPoints != null)
            {
                var tanListTop = new Dictionary<int[], double>();

                for (int j = 0; j < rightTopPoints.Count; j++)
                {
                    tan = (double)(rightTopPoints[j][1] - topPoint[1]) / (rightTopPoints[j][0] - topPoint[0]);
                    tanListTop.Add(rightTopPoints[j], tan);
                }

                var tanTop = tanListTop.Values.ToList();
                tanTop.Sort();
                topPoint = tanListTop.ToList().Find(c => c.Value == tanTop[tanTop.Count - 1]).Key;
                newList.Add(topPoint);
                //判断右侧是否还有点。
                xyList = xyList.Where(c => c[0] >= topPoint[0]).ToList();
                if (xyList!=null&&xyList.Count!=0)
                {
                    //判断右侧点首末是否相等
                    if (xyList[0][0] != xyList[xyList.Count - 1][0])
                    {
                        GetFenchTop(newList, topPoint,xyList);
                    }
                    else
                    {
                        newList.AddRange(xyList);
                        return;
                    }
                }
            }
        }
        private static void GetFenchBottom(List<int[]> newList, int[] bottomPoint, List<int[]> xyList)
        {
            var tan = 0.0;
            var rightBottomPoints = xyList.Where(c => c[0] > bottomPoint[0]).ToList();
            if (rightBottomPoints.Count != 0 && rightBottomPoints != null)
            {
                var tanListTop = new Dictionary<int[], double>();
                for (int j = 0; j < rightBottomPoints.Count; j++)
                {
                    tan = (double)(rightBottomPoints[j][1] - bottomPoint[1]) / (rightBottomPoints[j][0] - bottomPoint[0]);
                    tanListTop.Add(rightBottomPoints[j], tan);
                }
                var tanTop = tanListTop.Values.ToList();
                tanTop.Sort();
                bottomPoint = tanListTop.ToList().Find(c => c.Value == tanTop[0]).Key;
                newList.Add(bottomPoint);
                xyList = xyList.Where(c => c[0] > bottomPoint[0]).ToList();
                if (xyList != null && xyList.Count != 0)
                {
                    if (xyList[0][0] != xyList[xyList.Count - 1][0])
                    {
                        GetFenchBottom(newList, bottomPoint, xyList);
                    }
                }
            }
        }
        private static List<int[]> TwoDimensionXY(int[][] points)
        {
            var yList = points.OrderBy(c => c[0]).ToList();
            for (int i = 0; i < yList.Count; i++)
            {
                for (int j = i + 1; j < yList.Count; j++)
                {
                    if (yList[i][0] == yList[j][0])
                    {
                        if (yList[i][1] > yList[j][1])
                        {
                            var tmp = yList[i];
                            yList[i] = yList[j];
                            yList[j] = tmp;
                        }
                    }
                }

            }

            return yList;
        }
        private static int[][] Thin(List<int[]> list)
        {
            for (int i = 0; i < list.Count; i++)
            {
                for (int j=i+1; j < list.Count; j++)
                {
                    if (list[i][0] == list[j][0] && list[i][1] == list[j][1])
                    {
                        list.RemoveAt(j);
                        j--;
                    }
                }
            }
            return list.ToArray();
        }
    }