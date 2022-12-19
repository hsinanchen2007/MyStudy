sortQueue那行取消注释的话，就用了AStar排序，但是居然比不排序慢很多。

不理解啊，是不是因为这题的核心就是制造一堆阻塞块，把AStar给废掉了？

```
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;
import java.util.Optional;
import java.util.stream.Collectors;

class Solution {
    private static final int INDEXER_SIZE = 10000;

    private final Code originalCode = new Code("0000");

    private LinkedList<Code> listQueue = new LinkedList<>();

    public int openLock(String[] deadends, String target) {
        if (Arrays.asList(deadends).contains("0000")) {
            return -1;
        }
        
        Arrays.fill(Code.codeIndexer, null);
        Code.targetCode = new Code(target);
        List<Code> deadEndList = Arrays.stream(deadends).map(Code::new).collect(Collectors.toList());
        deadEndList.forEach(deadend -> {
            deadend.setDeadEnd();
            Code.codeIndexer[deadend.getIndex()] = deadend;
        });

        int step = 0;
        listQueue.add(originalCode);
        originalCode.setStep(step);
        while (!listQueue.isEmpty()) {
            Code currentStepCode = listQueue.poll();
            List<Code> nextStepCodeList = currentStepCode.generateCodesOfNextStep();

            Code possibleTarget = Code.getPossibleTargetCode();
            if (possibleTarget != null) {
                return possibleTarget.getStep();
            }

            listQueue.addAll(nextStepCodeList);
            // sortQueue();
        }

        return -1;
    }

    private void sortQueue() {
        listQueue.sort(Comparator.comparing(Code::getAstarStepsToTarget));
    }

    static class Code {
        private static final int LENGTH = 4;
        private static final int TEN = 10;
        private static final int INSCREASE_STEP = 1;
        private static final int DECREASE_STEP = 9;
        private static final int[] FACTORS = new int[]{1000, 100, 10, 1};
        private static Code targetCode = null;
        private static Code[] codeIndexer = new Code[INDEXER_SIZE];

        private int[] code = new int[LENGTH];
        private int index = 0;
        private boolean isDeadEnd = false;
        private int step = -1;
        private int aStarStepsToTarget = 0;

        Code(String text) {
            int value = Integer.parseInt(text);

            for (int i = 0; i < LENGTH; i++) {
                code[i] = (value / FACTORS[i]) % TEN;
            }

            generateIndex();
        }

        Code(int[] code) {
            this.code = code;
            generateIndex();
        }

        static Code getPossibleTargetCode() {
            return codeIndexer[targetCode.getIndex()];
        }

        int getIndex() {
            return index;
        }

        boolean isDeadEnd() {
            return isDeadEnd;
        }

        void setDeadEnd() {
            this.isDeadEnd = true;
        }

        int getStep() {
            return step;
        }

        void setStep(int step) {
            this.step = step;
        }

        boolean isTouched() {
            return step >= 0;
        }

        private void generateIndex() {
            for (int i = 0; i < LENGTH; i++) {
                index += code[i] * FACTORS[i];
            }

            aStarStepsToTarget = 0;
            if (targetCode != null) {
                for (int i = 0; i < LENGTH; i++) {
                    aStarStepsToTarget += getDistance(targetCode.code[i], code[i]);
                }
            }
        }

        private int getDistance(int num1, int num2) {
            int distance = Math.abs(num1 - num2);
            int theOtherwayAround = TEN - distance;

            return Math.min(distance, theOtherwayAround);
        }

        List<Code> generateCodesOfNextStep() {
            List<Code> codeList = new ArrayList<>();
            for (int i = 0; i < LENGTH; i++) {
                makeNewCode(i, INSCREASE_STEP).ifPresent(codeList::add);
                makeNewCode(i, DECREASE_STEP).ifPresent(codeList::add);
            }
            return codeList;
        }

        int getAstarStepsToTarget() {
            return aStarStepsToTarget + getStep();
        }

        private Optional<Code> makeNewCode(int position, int newCodeStep) {
            int[] newCode = new int[LENGTH];
            System.arraycopy(code, 0, newCode, 0, code.length);
            newCode[position] = (newCode[position] + newCodeStep) % TEN;
            Code theNewCode = new Code(newCode);

            if (codeIndexer[theNewCode.getIndex()] == null) {
                codeIndexer[theNewCode.getIndex()] = theNewCode;
                theNewCode.setStep(this.step + 1);
            } else {
                theNewCode = codeIndexer[theNewCode.getIndex()];
                if (theNewCode.isDeadEnd() || theNewCode.isTouched()) {
                    theNewCode = null;
                }
            }

            return Optional.ofNullable(theNewCode);
        }
    }
}
```
