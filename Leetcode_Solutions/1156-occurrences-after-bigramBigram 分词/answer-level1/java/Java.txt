```java
class Solution {
    public String[] findOcurrences(String text, String first, String second) {
        String[] letter = text.split(" ");
        
        List<String> list = new ArrayList<>();
        for(int i=0; i<letter.length-2; i++){
            if(letter[i].equals(first) && letter[i+1].equals(second)){
                list.add(letter[i+2]);
            }
        }
        String[] answer = new String[list.size()];
        for(int j=0;j<list.size();j++){
            answer[j] = list.get(j);
        }
        return answer;
    }
}