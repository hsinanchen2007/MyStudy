### 解题思路
核心思路是两个数组的标记，对这两个标记添加限制条件：
标记的左方元素个数与标记右方的元素个数相同或只差一个。
较小数组中的标记通过二分法在较小数组中找到正确的位置，每次移动的步伐就是较小数组长度的一半。
正确位置的条件即实现标记右边的元素总是比标记左边的元素大。

### 代码

```java
class Solution {
    public static double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int[] shorterArray = findShorterArray(nums1, nums2);
        int[] longerArray = findLongerArray(nums1, nums2);
        int shorterArrayLength = shorterArray.length;
        int longerArrayLength = longerArray.length;
        int totalLength = shorterArrayLength + longerArrayLength;
        int shorterArrayFlag = 0;
        int longerArrayFlag = totalLength / 2;
        int path = (shorterArrayLength + 1) / 2;
        boolean evenFlag = totalLength % 2 == 0 ? true : false;
        return findFinalShortArrayFlag(shorterArray, longerArray, shorterArrayFlag, longerArrayFlag, path, evenFlag);

    }

    public static int[] findShorterArray(int[] nums1, int[] nums2) {
        return nums1.length <= nums2.length ? nums1 : nums2;
    }

    public static int[] findLongerArray(int[] nums1, int[] nums2) {
        return nums1.length > nums2.length ? nums1 : nums2;
    }

    public static double findFinalShortArrayFlag(int[] shorterArray, int[] longerArray, int shorterArrayFlag, int longerArrayFlag, int path, boolean evenFlag) {
        int shorterFlagLeftValue = findBoundaryLeftValue(shorterArray, shorterArrayFlag);
        int shorterFlagRightValue = findBoundaryRightValue(shorterArray, shorterArrayFlag);
        int longerFlagLeftValue = findBoundaryLeftValue(longerArray, longerArrayFlag);
        int longerFlagRightValue = findBoundaryRightValue(longerArray, longerArrayFlag);
        if (shorterFlagLeftValue <= longerFlagRightValue && longerFlagLeftValue <= shorterFlagRightValue) {
            return evenFlag ? evenArrayResult(shorterFlagLeftValue, longerFlagLeftValue, shorterFlagRightValue, longerFlagRightValue) : oddArrayResult(shorterFlagRightValue, longerFlagRightValue);
        } else if (shorterFlagLeftValue > longerFlagRightValue) {
            shorterArrayFlag -= path;
            longerArrayFlag += path;
            path = (path + 1) / 2;
            return findFinalShortArrayFlag(shorterArray, longerArray, shorterArrayFlag, longerArrayFlag, path, evenFlag);
        } else if (longerFlagLeftValue > shorterFlagRightValue) {
            shorterArrayFlag += path;
            longerArrayFlag -= path;
            path = (path + 1) / 2;
            return findFinalShortArrayFlag(shorterArray, longerArray, shorterArrayFlag, longerArrayFlag, path, evenFlag);
        } else {
            return 0;
        }
    }

    public static double oddArrayResult(int shorterFlagRightValue, int longerFlagRightValue) {
        return shorterFlagRightValue < longerFlagRightValue ? (double) shorterFlagRightValue : (double) longerFlagRightValue;
    }

    public static double evenArrayResult(int shorterFlagLeftValue, int longerFlagLeftValue, int shorterFlagRightValue, int longerFlagRightValue) {
        int leftValue = shorterFlagLeftValue > longerFlagLeftValue ? shorterFlagLeftValue : longerFlagLeftValue;
        int rightValue = shorterFlagRightValue < longerFlagRightValue ? shorterFlagRightValue : longerFlagRightValue;
        return (double) (leftValue + rightValue) / 2;
    }

    public static int findBoundaryLeftValue(int[] array, int arrayFlag) {
        return arrayFlag <= 0 ? Integer.MIN_VALUE : array[arrayFlag - 1];
    }

    public static int findBoundaryRightValue(int[] array, int arrayFlag) {
        return arrayFlag >= array.length ? Integer.MAX_VALUE : array[arrayFlag];
    }

}
```


```java
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.CsvSource;

import java.util.Arrays;

import static org.junit.Assert.assertArrayEquals;
import static org.junit.Assert.assertEquals;

public class SolutionTest {
    @ParameterizedTest
    @CsvSource({
            "'1,3,4,9','2,4,6','2,4,6'",
            "'1','2,4,6','1'",
            "'2,3','2,4','2,3'"
    })
    public void findShorterArrayTest(String arrayInput1, String arrayInput2, String arrayExpected) {
        int[] arrayInput1Covert = Arrays.stream(arrayInput1.split(",")).mapToInt(Integer::parseInt).toArray();
        int[] arrayInput2Covert = Arrays.stream(arrayInput2.split(",")).mapToInt(Integer::parseInt).toArray();
        int[] arrayExpectedCovert = Arrays.stream(arrayExpected.split(",")).mapToInt(Integer::parseInt).toArray();
        assertArrayEquals(arrayExpectedCovert, Solution.findShorterArray(arrayInput1Covert, arrayInput2Covert));
    }

    @ParameterizedTest
    @CsvSource({
            "'1,3,4,9','2,4,6','1,3,4,9'",
            "'1','2,4,6','2,4,6'",
            "'2,3','2,4','2,4'"
    })
    public void findLongerArrayTest(String arrayInput1, String arrayInput2, String arrayExpected) {
        int[] arrayInput1Covert = Arrays.stream(arrayInput1.split(",")).mapToInt(Integer::parseInt).toArray();
        int[] arrayInput2Covert = Arrays.stream(arrayInput2.split(",")).mapToInt(Integer::parseInt).toArray();
        int[] arrayExpectedCovert = Arrays.stream(arrayExpected.split(",")).mapToInt(Integer::parseInt).toArray();
        assertArrayEquals(arrayExpectedCovert, Solution.findLongerArray(arrayInput1Covert, arrayInput2Covert));
    }

    @ParameterizedTest
    @CsvSource({
            "'1,3,4,9',0,-2147483648",
            "'2,4,6',2,4",
            "'2,3',2,3"
    })
    public void findBoundaryLeftValueTest(String arrayInput, int flagInput, int valueExpected) {
        int[] arrayInputCovert = Arrays.stream(arrayInput.split(",")).mapToInt(Integer::parseInt).toArray();
        assertEquals(valueExpected, Solution.findBoundaryLeftValue(arrayInputCovert, flagInput));
    }

    @ParameterizedTest
    @CsvSource({
            "'1,3,4,9',0,1",
            "'2,4,6',2,6",
            "'2,3',2,2147483647"
    })
    public void findBoundaryRightValueTest(String arrayInput, int flagInput, int valueExpected) {
        int[] arrayInputCovert = Arrays.stream(arrayInput.split(",")).mapToInt(Integer::parseInt).toArray();
        assertEquals(valueExpected, Solution.findBoundaryRightValue(arrayInputCovert, flagInput));
    }

    @ParameterizedTest
    @CsvSource({
            "'1,2,3,4','5,6,7,8',4.5",
            "'1,3,4,9','2,4,6',4",
            "'1','2,4,6',3",
            "'2,3','4',3",
            "'1','1',1"
    })
    public void findMedianSortedArraysTest(String arrayInput1, String arrayInput2, double valueExpected) {
        int[] arrayInput1Covert = Arrays.stream(arrayInput1.split(",")).mapToInt(Integer::parseInt).toArray();
        int[] arrayInput2Covert = Arrays.stream(arrayInput2.split(",")).mapToInt(Integer::parseInt).toArray();
        assertEquals(valueExpected, Solution.findMedianSortedArrays(arrayInput1Covert, arrayInput2Covert), 0);
    }
}
```