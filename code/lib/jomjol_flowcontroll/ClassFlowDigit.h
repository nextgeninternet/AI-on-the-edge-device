#pragma once
#include "ClassFlowImage.h"
#include "Helper.h"

#include <string>

struct roi {
    int posx, posy, deltax, deltay;
    int resultklasse;
    string name;
    roi* next;
};

class ClassFlowDigit :
    public ClassFlowImage
{
protected:
    std::vector<roi*> ROI;
    string cnnmodelfile;
    int modelxsize, modelysize;

    bool doNeuralNetwork(string time); 
    bool doAlignAndCut(string time); 

public:
    ClassFlowDigit();
    ClassFlowDigit(std::vector<ClassFlow*>* lfc);
    bool ReadParameter(FILE* pfile, string& aktparamgraph);
    bool doFlow(string time);
    string getHTMLSingleStep(string host); 
    string getReadout();
   	std::vector<HTMLInfo*> GetHTMLInfo();

    string name(){return "ClassFlowDigit";};
};

