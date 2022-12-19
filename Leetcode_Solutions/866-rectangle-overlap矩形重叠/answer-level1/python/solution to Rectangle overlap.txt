### 解题思路
here just consider the distance between the center point of the two Rectangle
and compare they  with side lenth. if a<0 so return True it means that there is overlap ,otherwise return false. I think that by this way we can reduce the time to caculate but need more room to store the var 

### 代码

```python
class Solution(object):
    def isRectangleOverlap(self, rect1, rect2):
        """
        :type rec1: List[int]
        :type rec2: List[int]
        :rtype: bool
        """
        center_x1,center_y1=(rect1[0]+rect1[2])/2,(rect1[1]+rect1[3])/2
        center_x2,center_y2=(rect2[0]+rect2[2])/2,(rect2[1]+rect2[3])/2
        distance_x=(abs(rect1[0]-rect1[2])+abs(rect2[0]-rect2[2]))/2
        distance_y=(abs(rect1[1]-rect1[3])+abs(rect2[1]-rect2[3]))/2
        cneterdis_x=abs(center_x1-center_x2)
        cneterdis_y=abs(center_y1-center_y2)
        a=cneterdis_x-distance_x
        b=cneterdis_y-distance_y
        if a<0 and b<0:
          return True
        else:
         return False

```