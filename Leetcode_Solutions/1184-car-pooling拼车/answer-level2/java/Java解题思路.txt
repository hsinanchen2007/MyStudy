//例如：int[][] trips = {{2,1,5}, {3,5,7}};
//转换成List之后：[1,2][5,-2],[5,3],[7,-3]
//从左到右依次求和，如果存在和超过capacity,则不能完成任务；否则可以完成任务
class Solution {

    class PositionInfo {
        public PositionInfo(int positionValue, int passengerNum) {
            this.passengerNum = passengerNum;
            this.positionValue = positionValue;
        }

        public int positionValue;
        public int passengerNum;
    }

    public boolean carPooling(int[][] trips, int capacity) {

        List<PositionInfo> positionInfo = transferArray2List(trips);
        sortPositionInfo(positionInfo);
        boolean result = judgeFinishTask(positionInfo,capacity);
        return result;
    }

    private List<PositionInfo> transferArray2List(int[][] trips) {
        List<PositionInfo> positionsInfo = new ArrayList<>();
        for (int i = 0; i < trips.length; i++) {
            PositionInfo startPosInfo = new PositionInfo(trips[i][1], trips[i][0]);
            positionsInfo.add(startPosInfo);
            PositionInfo endPosInfo = new PositionInfo(trips[i][2], -1 * trips[i][0]);
            positionsInfo.add(endPosInfo);
        }
        return positionsInfo;
    }

    private void sortPositionInfo(List<PositionInfo> positionInfo) {
        Collections.sort(positionInfo, new Comparator<PositionInfo>() {
            @Override
            public int compare(PositionInfo o1, PositionInfo o2) {
                int result = 0;
                if (o1.positionValue != o2.positionValue) {
                    result = Integer.compare(o1.positionValue, o2.positionValue);
                } else {
                    result = Integer.compare(o1.passengerNum, o2.passengerNum);
                }
                return result;
            }
        });
    }

    private boolean judgeFinishTask(List<PositionInfo> positionInfos, int capacity) {
        boolean isFinish = true;
        int currentPassengers = 0;
        for(PositionInfo positionInfo : positionInfos) {
            currentPassengers = currentPassengers + positionInfo.passengerNum;
            if(currentPassengers > capacity) {
                isFinish = false;
                break;
            }
        }
        return isFinish;
    }
}