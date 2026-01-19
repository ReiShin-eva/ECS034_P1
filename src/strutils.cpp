#include "strutils.h"
#include <string>
#include <vector>
#include <iostream>

//Slice Function
std::string Slice(const std::string &str, ssize_t start, ssize_t end=0){
  std::string out;
  for(int i = 0; i < (str.size() - end); ++i){
    if(i >= start){
      out = out + str[i];
    } else {
      continue;
    }
  }
  return out;
}

//Capitalize Function
std::string Capitalize(const std::string &str){
  std::string out = str;
  out[0] =  std::toupper(out[0]);
  for(int i = 1; i < out.size(); i++){
    out[i] = std::tolower(out[i]);
  }
  return out;
}

//Upper-LowerFunctions
//UpperFunction
std::string Upper(const std::string &str){
  std::string out = str;
  for(int i = 0; i < str.size(); i++){
    out[i] = std::toupper(out[i]);
  }
  return out;
}
//Lower Functions
std::string Lower(const std::string &str){
  std::string out = str;
  for(int i = 0; i < str.size(); i++){
    out[i] = std::tolower(out[i]);
  }
  return out;
}

//Strip Functions
//LStripFunction
std::string LStrip(const std::string &str){
  bool flag = false;
  std::string out;
  for(int i = 0; i < str.size(); i++){
    char c = str[i];
    if(flag == false && c == ' '){
      continue;
    } else{
      flag = true;
      out = out + str[i];
    }
  }
  return out;
}
//RStripFunction
std::string RStrip(const std::string &str){
  std::string out;
  int n = 0;
  for(int i = 0; i < str.size(); i++){
    if(str[str.size() - i - 1] == ' '){
      n = n + 1;
    } else { break; }
  }
  for(int i = 0; i < str.size() - n; i++){
    out = out + str[i];
  }
  return out;
}
//CenterFunction
std::string Strip(const std::string &str){
    std::string out;
  int n = 0;
  for(int i = 0; i < str.size(); i++){
    if(str[str.size() - i - 1] == ' '){
      n = n + 1;
    } else { break; }
  }
  for(int i = 0; i < str.size() - n; i++){
    out = out + str[i];
  }
  bool flag = false;
  std::string out1;
  for(int i = 0; i < out.size(); i++){
    char c = out[i];
    if(flag == false && c == ' '){
      continue;
    } else{
      flag = true;
      out1 = out1 + str[i];
    }
  }
  return out1;
}

//JustFunctions
//CenterFunction
std::string Center(const std::string &str, int width, char fill = ' '){
  if(width <= str.size()){
    return str;
  } else{
    int n = width - str.size();
    std::string out = str;
    bool left = true;
    bool right = false;
    for(int i = 0; i < n; i++){
      if(left){
        out = fill + out;
        right = true;
        left = false;
      } else{
        out = out + fill;
        right = false;
        left = true;
      }
    }
    return out;
  }
}
//LJust Function
std::string LJust(const std::string &str, int width, char fill = ' '){
    if(width <= str.size()){
    return str;
  } else{
    int n = width - str.size();
    std::string out = str;
    for(int i = 0; i < n; i++){
      out = fill + out;
    }
    return out;
  }
}
//RJust Function
std::string RJust(const std::string &str, int width, char fill = ' '){
    if(width <= str.size()){
    return str;
  } else{
    int n = width - str.size();
    std::string out = str;
    for(int i = 0; i < n; i++){
      out = out + fill;
    }
    return out;
  }
}

//Replace Function
std::string Replace(const std::string &str, const std::string &old, const std::string &rep){
  if(old.empty()){ return str; }
  std::string out;
	std::string counter;
	for(int i = 0; i < str.size(); i++){
		for(int j = 0; j < old.size(); j++){
			if((i + j) >= str.size()){break;}
			counter = counter + str[i + j];
		}
		if(counter == old){
			out = out + rep;
			
		} else{ out = out + str[i]; }
		counter = "";
	}
  return out;
}

//Split Function
std::vector<std::string> Split(const std::string &str, const std::string &splt = "") {
	std::string look;
	if(splt == ""){ look = " "; } else{ look = splt; }
	int count = 1;
	std::vector<int> idx;
	std::string counter;	
	for(int i = 0; i  < str.size(); i++){
		counter = "";
		for(int j = 0; j < look.size(); j++){
			if((i + j) >= str.size()){break;}
			counter = counter + str[i + j];
		}
		if(counter == look){ count++; idx.push_back(i); } else{ continue; }
		counter = "";
	}
	std::vector<std::string> out(count);
	int start = 0;
	for(int i = 0; i < idx.size(); i++){
		out[i] = str.substr(start, idx[i] - start);
		start = idx[i] + look.size();
	}
	out[count - 1] = str.substr(start);
	return out;
}

//Join Function
std::string Join(const std::string &str, const std::vector<std::string> &vect) {
    std::string out;
    for (int i = 0; i < vect.size(); ++i) {
        out += vect[i];
        if (i < vect.size() - 1) {
            out += str;  
        }
    }
    return out;
}

//ExpandTabs
std::string ExpandTabs(const std::string &str, int tabsize = 4) {
    std::string out;
    int col = 0; 
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '\t') {
          int spaces = tabsize - (col % tabsize);
          out.append(spaces, ' ');
          col += spaces;
        } else {
          out += str[i];
          col++;
        }
    }
    return out;
}

//
int EditDistance(const std::string &left, const std::string &right, bool ignorecase = false) {
    int n = left.size();
    int m = right.size();
    std::vector<std::vector<int>> tab(n + 1, std::vector<int>(m + 1));
    for (int i = 0; i <= n; i++)
        tab[i][0] = i;
    for (int j = 0; j <= m; j++)
        tab[0][j] = j;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char a = left[i - 1];
            char b = right[j - 1];
            if (ignorecase) {
                a = Lower(a);
                b = Lower(b);
            }
            int cost;
            if(a == b) { cost = 0;} else { cost = 1;}
            tab[i][j] = std::min({
                tab[i - 1][j] + 1,
                tab[i][j - 1] + 1,
                tab[i - 1][j - 1] + cost
            });
        }
    }
    return tab[n][m];
}





























