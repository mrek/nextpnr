/*
 *  nextpnr -- Next Generation Place and Route
 *
 *  Copyright (C) 2018  Miodrag Milanovic <miodrag@symbioticeda.com>
 *
 *  Permission to use, copy, modify, and/or distribute this software for any
 *  purpose with or without fee is hereby granted, provided that the above
 *  copyright notice and this permission notice appear in all copies.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 *  WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 *  MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 *  ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 *  WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 *  ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 *  OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../basewindow.h"
#include "worker.h"

NEXTPNR_NAMESPACE_BEGIN

class MainWindow : public BaseMainWindow
{
    Q_OBJECT

  public:
    explicit MainWindow(std::unique_ptr<Context> context, ArchArgs args, QWidget *parent = 0);
    virtual ~MainWindow();

  public:
    void createMenu();
    void load_json(std::string filename, std::string pcf);
    void load_pcf(std::string filename);
  protected Q_SLOTS:
    virtual void new_proj();
    virtual void open_proj();
    virtual bool save_proj();

    void open_json();
    void open_pcf();
    void budget();
    void place();
    void save_asc();

    void loadfile_finished(bool status);
    void loadpcf_finished(bool status);
    void saveasc_finished(bool status);
    void pack_finished(bool status);
    void budget_finish(bool status);
    void place_finished(bool status);
    void route_finished(bool status);

    void taskCanceled();
    void taskStarted();
    void taskPaused();

    void newContext(Context *ctx);

  private:
    void disableActions();

    TaskManager *task;
    QAction *actionLoadJSON;
    QAction *actionLoadPCF;
    QAction *actionPack;
    QAction *actionAssignBudget;
    QAction *actionPlace;
    QAction *actionRoute;
    QAction *actionSaveAsc;
    QAction *actionPlay;
    QAction *actionPause;
    QAction *actionStop;

    bool timing_driven;
    ArchArgs chipArgs;

    std::string currentProj;
    std::string currentJson;
    std::string currentPCF;
};

NEXTPNR_NAMESPACE_END

#endif // MAINWINDOW_H
