```
 public String simplifyPath(String path) {
        Stack<String> pathStack = new Stack<>();

        Stream.of(path.split("/")).filter(s -> Objects.nonNull(s) & !".".equals(s) & s.length() > 0).forEach(
                s -> {
                    if ("..".equals(s)){
                        if (!pathStack.isEmpty())
                            pathStack.pop();
                    }
                    else pathStack.push(s);
                }
                );
        return "/" + pathStack.stream().collect(Collectors.joining("/"));
    }
```
