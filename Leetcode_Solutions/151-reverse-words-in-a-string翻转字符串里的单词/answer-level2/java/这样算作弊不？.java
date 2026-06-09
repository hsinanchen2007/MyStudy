   public String reverseWords(String s) {
        List<String> ss = Arrays.stream(s.split(" ")).map(x->x.replaceAll(" ",""))
            .filter(x->!x.isEmpty()).collect(Collectors.toList());
        Collections.reverse(ss);
        return String.join(" ",ss);
    }

这样算作弊不？