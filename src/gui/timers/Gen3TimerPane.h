//
// Created by Dylan Meadows on 2020-03-26.
//

#ifndef EONTIMER_GEN3TIMERPANE_H
#define EONTIMER_GEN3TIMERPANE_H

#include <QWidget>
#include <services/settings/Gen3TimerSettings.h>
#include <services/CalibrationService.h>
#include <services/TimerService.h>
#include <services/timers/FrameTimer.h>
#include <QSpinBox>

namespace gui::timer {
    class Gen3TimerPane : public QWidget {
    Q_OBJECT
    private:
        service::settings::Gen3TimerSettings *settings;
        const service::timer::FrameTimer *frameTimer;
        const service::CalibrationService *calibrationService;
        service::TimerService *timerService;
        QSpinBox *calibration;
        QSpinBox *preTimer;
        QSpinBox *targetFrame;
        QSpinBox *frameHit;
    public:
        Gen3TimerPane(service::settings::Gen3TimerSettings *settings,
                      const service::timer::FrameTimer *frameTimer,
                      const service::CalibrationService *calibrationService,
                      service::TimerService *timerService,
                      QWidget *parent = nullptr);

        void calibrateTimer();

        void updateTimer();

    private:
        void initComponents();
    };
}

#endif //EONTIMER_GEN3TIMERPANE_H