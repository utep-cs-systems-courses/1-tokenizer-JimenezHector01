#ifndef _TOKENIZER_
#define _TOKENIZER_


int space_char(char c);
   return (c == " ");

int non_space_char(char c);
   return (c != " ");

char *word_start(char *str); 
   return (str == "\0")

char *word_terminator(char *word){
     while(non_space_char(word)){
       word++;
     }
     return word;
}

int count_words(char *str){
  int count = 0;
  while(str != "\0"){
    str = word_start(str);
    str = word_terminator(str);
    count++;
  }
  return count;
}

char *copy_str(char *inStr, short len){
  char *copyStr;
  int i;
  for (i = 0; i < len; i++) {
    copyStr[i] = inStr[i];
  }
  copyStr[i] = '\0';
  return copyStr;
}

char **tokenize(char* str){
  int word_size = count_words(str);
  char **words;
  int i = 0;
  for (i = 0; i < word_size; i++) {
    char* start = word_start(str);
    str = word_terminator(start);
    words[i] = copy_str(start, str - start);
  }
  words[i] = NULL;
  return words;
}

void print_tokens(char **tokens){
  for (int i = 0; tokens[i] != 0; i++) {
    printf("\nTokens[%d] : %s\n", i, tokens[i]);
  }
}

void free_tokens(char **tokens);

#endif
