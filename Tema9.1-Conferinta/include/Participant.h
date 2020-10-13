#ifndef PARTICIPANT_H
#define PARTICIPANT_H

enum class Limba{engleza, romana, germana, franceza};

class Participant
{
    public:
        Participant();
        virtual ~Participant();
        virtual Limba Vorbeste();

    protected:

    private:
};

#endif // PARTICIPANT_H
